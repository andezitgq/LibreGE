#include "projectmanager.h"
#include "project/debug.h"
#include "project/create_project_form.h"

#include <QFileDialog>
#include <QApplication>
#include <QDesktopWidget>

#include <iostream>
#include <thread>

#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <X11/Xlib.h>

#define MAX_EVENTS  1024
#define LEN_NAME    48
#define EVENT_SIZE  ( sizeof (struct inotify_event) )
#define BUF_LEN     ( MAX_EVENTS * ( EVENT_SIZE + LEN_NAME ))

using namespace std;
using std::thread;

ProjectManager::ProjectManager()
{

}

string      ProjectManager::dir         = "";
bool        ProjectManager::isChecking  = false;
QListWidget *ProjectManager::listWidget = NULL;

void check_changes(const char *filePath){
    int length, i = 0, wd;
        int fd;
        char buffer[BUF_LEN];

        fd = inotify_init();
        if ( fd < 0 ) {
            Debug::Inotify("Couldn't initialize inotify");
        }

        wd = inotify_add_watch(fd, filePath, IN_CREATE | IN_MODIFY | IN_DELETE);

        if (wd == -1)
        {
            Debug::Inotify("Couldn't add watch to '" + string(filePath) + "'");
            Debug::Inotify("WD = " + to_string(wd));
        }
        else
        {
            Debug::Inotify("Watching '" + string(filePath) + "'");
        }

        while(true)
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
                        Debug::Inotify("The directory " + string(event->name) + " was Created");
                    else
                        Debug::Inotify("The file " + string(event->name) + " was Created with WD " + to_string(event->wd));
                }

                if ( event->mask & IN_MODIFY) {
                    if (event->mask & IN_ISDIR)
                        Debug::Inotify("The directory " + string(event->name) + " was modified");
                    else
                        Debug::Inotify("The file " + string(event->name) + " was modified with WD " + to_string(event->wd));
                }

                if ( event->mask & IN_DELETE) {
                    if (event->mask & IN_ISDIR)
                        Debug::Inotify("The directory " + string(event->name) + " was deleted");
                    else
                        Debug::Inotify("The file " + string(event->name) + " was deleted with WD " + to_string(event->wd));
                }


                    i += EVENT_SIZE + event->len;
                }
            }
        }
    inotify_rm_watch( fd, wd );
    close( fd );
}

void ProjectManager::NewProjectMenu(string projectDir)
{
    ProjectManager::dir = projectDir;
    CreateProjectForm *cpf = new CreateProjectForm();
    cpf->setAttribute(Qt::WA_DeleteOnClose);
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width() - cpf->width()) / 2;
    int y = (screenGeometry.height() - cpf->height()) / 2;
    cpf->move(x, y);
    cpf->show();
}



void ProjectManager::CreateProject(string projectName, string mainScene, string type){
    Json::Value root;

    root["Project"]["Name"] = projectName;
    root["Project"]["Scenes"][mainScene]["SceneName"] = mainScene;
    root["Project"]["Type"] = type;

    ofstream out(ProjectManager::dir + "/Project.json");
    out << root.toStyledString();
    out.close();
    FileManager *fm = new FileManager();
    fm->fman_setup(ProjectManager::listWidget, ProjectManager::dir.c_str());

    thread fileCheckThr(check_changes, ProjectManager::dir.c_str());

    if(ProjectManager::isChecking == true){
        fileCheckThr.join();
    }
}

void ProjectManager::OpenProject(){

}
