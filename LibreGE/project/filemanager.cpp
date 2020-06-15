#include "filemanager.h"
#include "mainwindow.h"

#include <fstream>
#include <sstream>

FileManager::FileManager()
{

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
       strcmp(entry->d_name, ".directory") != 0 &&
       strcmp(entry->d_name, "Project.json") != 0 &&
       strcmp(entry->d_name, "FileManager.json") != 0)
    {
        root[entry->d_name]["type"] = fileType;
        root[entry->d_name]["icon"] = iconPath;
        QString entryIcon = QString::fromStdString(iconPath);
        QString entryName = QString::fromStdString(entry->d_name);
        QIcon *icon = new QIcon(entryIcon);
        QListWidgetItem *item = new QListWidgetItem(*icon, entryName, fman);
    }
}

void FileManager::fman_setup(QListWidget *fman, const char *path){
    struct dirent *entry;
    DIR *dir = opendir(path);

    if (dir == NULL) {
       cout << "Folder not found!" << endl;
    }
    Json::Value root;
    while ((entry = readdir(dir)) != NULL) {
        string strPath(path);
        string strFile(entry->d_name);
        string strDir = strPath + "/" + strFile;
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
