#include "mainwindow.h"
#include "project/filemanager.h"
#include <QApplication>
#include <GL/glut.h>
#include <iostream>
#include <dirent.h>
#include <sys/types.h>
#include <thread>

using namespace std;
using std::thread;

void windowInit(MainWindow w){
    w.show();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    /*thread windowThr(windowInit, w);
    thread fileCheckThr(FileManager::check_changes, "123");

    windowThr.join();
    fileCheckThr.join();*/

    return a.exec();
}

