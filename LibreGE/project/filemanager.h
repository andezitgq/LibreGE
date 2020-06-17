#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

#include <iostream>
#include <dirent.h>
#include <sys/types.h>
#include <string>
#include <jsoncpp/json/value.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/inotify.h>
#include <limits.h>

#include "mainwindow.h"
using namespace std;

class FileManager
{
public:
    FileManager();
    ~FileManager();
    bool        check_ext(string filename, string ext);
    void        fman_setup(QListWidget *fman, string path);
    static void check_changes(const char *filePath);

private:
    void setFmanJSON(Json::Value root,
                 struct dirent *entry,
                 const string iconPath,
                 const string fileType,
                 QListWidget *fman);
};

#endif // FILEMANAGER_H
