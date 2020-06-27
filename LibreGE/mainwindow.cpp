#include <QMessageBox>
#include <QFileDialog>

#include <iostream>
#include <string>

#include "projectmanager.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "editor/formeditor.h"
#include "ui_formeditor.h"

#include "project/filemanager.h"
#include "project/debug.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::showMaximized();
    ProjectManager::listWidget = ui->file_manager;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openEditor_clicked()
{
    FormEditor *h = new FormEditor;
    h->setAttribute(Qt::WA_DeleteOnClose);
    h->show();
}


void MainWindow::on_actionNew_triggered()
{

}

void MainWindow::on_actionCreate_project_triggered()
{
    QString dir_str = QFileDialog::getExistingDirectory(this, tr("Select"),"/home",QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(dir_str != NULL){
        string dir = dir_str.toStdString();
        ProjectManager::NewProjectMenu(dir);
    } else {
        Debug::Error("Folder isn't selected!");
    }
}
