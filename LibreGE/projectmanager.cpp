#include "projectmanager.h"
#include "project/create_project_form.h"
#include <QFileDialog>
#include <iostream>
#include <QApplication>
#include <X11/Xlib.h>
#include <QDesktopWidget>
using namespace std;

ProjectManager::ProjectManager(QListWidget *listWidget)
{
    this->dir = "";
    this->listWidget = listWidget;
}

void ProjectManager::NewProjectMenu(string projectDir)
{
    this->dir = projectDir;
    CreateProjectForm *cpf = new CreateProjectForm(this);
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

    ofstream out(this->dir + "/Project.json");
    out << root.toStyledString();
    out.close();
    FileManager *fm = new FileManager();
    fm->fman_setup(this->listWidget, this->dir.c_str());
}

void ProjectManager::OpenProject(){

}
