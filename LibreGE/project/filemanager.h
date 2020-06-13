#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

#include <iostream>
#include <dirent.h>
#include <sys/types.h>
#include <string>
#include <json/value.h>

#include "mainwindow.h"
using namespace std;

class FileManager
{
public:
    FileManager();
    ~FileManager();
    bool check_ext(string filename, string ext);
    void fman_setup(QListWidget *fman, const char *path);

private:
    void setFmanJSON(Json::Value root,
                 struct dirent *entry,
                 const string iconPath,
                 const string fileType,
                 QListWidget *fman);
};

#endif // FILEMANAGER_H
