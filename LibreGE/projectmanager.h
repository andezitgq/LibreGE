#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H

#include <fstream>
#include <jsoncpp/json/value.h>
#include <string>

#include <QListWidget>

#include "project/filemanager.h"
using std::string;

class ProjectManager
{

public:
    QListWidget *listWidget;
    ProjectManager(QListWidget *listWidget);
    ~ProjectManager();
    void NewProjectMenu(string projectDir);
    void CreateProject(string projectName, string mainScene, string type);
    void OpenProject();
    string dir;
};

#endif // PROJECTMANAGER_H
