#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QFileSystemWatcher>

#include <iostream>
#include <string>
#include <dirent.h>
#include <sys/types.h>
#include <jsoncpp/json/value.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/inotify.h>
#include <limits.h>

#include "mainwindow.h"
using namespace std;

class FileManager : public QObject
{
    Q_OBJECT
public:
    explicit    FileManager(QObject *parent = nullptr);
    bool        check_ext(string filename, string ext);
    void        fman_setup(QListWidget *fman, string path);
    bool        SetFSWatcher();

private:
    void setFmanJSON(Json::Value root,
                 struct dirent *entry,
                 const string iconPath,
                 const string fileType,
                 QListWidget *fman);

private slots:
    static void changed(const QString &flName);
};

#endif // FILEMANAGER_H
