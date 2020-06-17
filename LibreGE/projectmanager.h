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
    ProjectManager();
    ~ProjectManager();
    static void NewProjectMenu(string projectDir);
    static void CreateProject(string projectName, string mainScene, string type);
    static void OpenProject();

    static string       dir;
    static bool         isChecking;
    static QListWidget *listWidget;
};

#endif // PROJECTMANAGER_H
