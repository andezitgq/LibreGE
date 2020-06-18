#include <QApplication>
#include <GL/glut.h>

#include <iostream>
#include <thread>

#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "mainwindow.h"
#include "project/filemanager.h"
#include "projectmanager.h"

#define MAX_EVENTS  1024
#define LEN_NAME    24
#define EVENT_SIZE  ( sizeof (struct inotify_event) )
#define BUF_LEN     ( MAX_EVENTS * ( EVENT_SIZE + LEN_NAME ))

using namespace std;
using std::thread;

void check_changes(const char *filePath);

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    thread fileCheckThr(check_changes, ProjectManager::dir.c_str());
    if(ProjectManager::isChecking == true){
        cout << "Thread starting...\n";
        fileCheckThr.join();
    }

    return a.exec();
}

void check_changes(const char *filePath){
    cout << "Hello World\n";
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

