#include "projectmanager.h"
#include "project/debug.h"
#include "project/create_project_form.h"

#include <QFileDialog>
#include <QApplication>
#include <QDesktopWidget>
#include <QTimer>

#include <iostream>

using namespace std;

ProjectManager::ProjectManager()
{

}

QFileSystemWatcher *ProjectManager::fsWatcher   = new QFileSystemWatcher();
string              ProjectManager::dir         = "";
QListWidget        *ProjectManager::listWidget = NULL;

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

    cout << ProjectManager::dir.c_str() << endl;
    string assetsString = ProjectManager::dir + "/assets";
    bool isWatching = ProjectManager::fsWatcher->addPath(QString::fromUtf8(assetsString.c_str()));

    if(isWatching)          Debug::Log("Path '" + assetsString + "' is watching...");
    if(fm->SetFSWatcher())  Debug::Log("FSWatcher connected!");
    delete fm;
}

void ProjectManager::OpenProject(){

}
