#include "filemanager.h"
#include "mainwindow.h"
#include "projectmanager.h"

#include <fstream>
#include <sstream>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_EVENTS 1024
#define LEN_NAME 24
#define EVENT_SIZE  ( sizeof (struct inotify_event) )
#define BUF_LEN     ( MAX_EVENTS * ( EVENT_SIZE + LEN_NAME ))

FileManager::FileManager()
{

}

void FileManager::check_changes(const char *filePath){
    int length, i = 0, wd;
        int fd;
        char buffer[BUF_LEN];

        fd = inotify_init();
        if ( fd < 0 ) {
            perror( "Couldn't initialize inotify");
        }

        wd = inotify_add_watch(fd, filePath, IN_CREATE | IN_MODIFY | IN_DELETE);

        if (wd == -1)
        {
            printf("Couldn't add watch to %s\n",filePath);
        }
        else
        {
            printf("Watching:: %s\n",filePath);
        }

        while(ProjectManager::isChecking == true)
        {
            i = 0;
            length = read( fd, buffer, BUF_LEN );

            if ( length < 0 ) {
                perror( "read" );
            }

            while ( i < length ) {
            struct inotify_event *event = ( struct inotify_event * ) &buffer[ i ];
            if ( event->len ) {
                if ( event->mask & IN_CREATE) {
                    if (event->mask & IN_ISDIR)
                        printf( "The directory %s was Created.\n", event->name );
                    else
                        printf( "The file %s was Created with WD %d\n", event->name, event->wd );
                }

                if ( event->mask & IN_MODIFY) {
                    if (event->mask & IN_ISDIR)
                        printf( "The directory %s was modified.\n", event->name );
                    else
                        printf( "The file %s was modified with WD %d\n", event->name, event->wd );
                }

                if ( event->mask & IN_DELETE) {
                    if (event->mask & IN_ISDIR)
                        printf( "The directory %s was deleted.\n", event->name );
                    else
                        printf( "The file %s was deleted with WD %d\n", event->name, event->wd );
                }


                    i += EVENT_SIZE + event->len;
                }
            }
        }
    inotify_rm_watch( fd, wd );
    close( fd );
}

bool FileManager::check_ext(string filename, string ext) {
    string fn = filename;
    if(fn.substr(fn.find_last_of(".") + 1) == ext) {
      return true;
    } else {
      return false;
    }
}

void FileManager::setFmanJSON(Json::Value root,
                          struct dirent *entry,
                          const string iconPath,
                          const string fileType,
                          QListWidget *fman)
{
    if(strcmp(entry->d_name, ".") != 0 &&
       strcmp(entry->d_name, "..") != 0 &&
       strcmp(entry->d_name, ".directory") != 0)
    {
        root[entry->d_name]["type"] = fileType;
        root[entry->d_name]["icon"] = iconPath;
        QString entryIcon = QString::fromStdString(iconPath);
        QString entryName = QString::fromStdString(entry->d_name);
        QIcon *icon = new QIcon(entryIcon);
        QListWidgetItem *item = new QListWidgetItem(*icon, entryName, fman);
    }
}

void FileManager::fman_setup(QListWidget *fman, string path){
    struct dirent *entry;
    string assetsPath = path + "/assets";
    mkdir(assetsPath.c_str(), 0777);
    DIR *dir = opendir(assetsPath.c_str());

    Json::Value root;
    while ((entry = readdir(dir)) != NULL) {
        string strPath(path);
        string strFile(entry->d_name);
        string strDir = strPath + "/assets/" + strFile;
        DIR *testDir = opendir(strDir.c_str());
        root[entry->d_name]["path"] = strDir;
        if(testDir != NULL){
            this->setFmanJSON(root, entry, ":/fman/fman/folder.svg", "folder", fman);
        } else if(check_ext(entry->d_name, "cpp")) {
            this->setFmanJSON(root, entry, ":/fman/fman/folder.svg", "cpp", fman);
        } else if(check_ext(entry->d_name, "h")) {
            this->setFmanJSON(root, entry, ":/fman/fman/folder.svg", "h", fman);
        } else if(check_ext(entry->d_name, "png") || check_ext(entry->d_name, "jpg") || check_ext(entry->d_name, "jpeg")) {
            this->setFmanJSON(root, entry, ":/fman/fman/folder.svg", "image", fman);
        } else if(check_ext(entry->d_name, "txt")) {
            this->setFmanJSON(root, entry, ":/fman/fman/folder.svg", "text", fman);
        } else {
            this->setFmanJSON(root, entry, ":/fman/fman/folder.svg", "nan", fman);
        }
    }
    string strPath(path);
    string strDir = strPath + "/FileManager.json";

    ifstream inFile;
    inFile.open(strDir.c_str());

    string temp;
    stringstream ss;
    ss << inFile.rdbuf();
    temp = ss.str();

    if(temp != root.toStyledString()){
        ofstream outFile(strDir.c_str());
        outFile << "";
        outFile << root.toStyledString();
        outFile.close();
    }

    inFile.close();
    closedir(dir);
}
