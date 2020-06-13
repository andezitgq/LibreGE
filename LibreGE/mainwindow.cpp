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

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::showMaximized();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//:==============:FORM:TRIGGERS:===========:

//:===:BUTTONS:===:

void MainWindow::on_openEditor_clicked()
{
    FormEditor *h = new FormEditor;
    h->setAttribute(Qt::WA_DeleteOnClose);
    h->show();
}


//:====:MENU:====:

void MainWindow::on_actionNew_triggered()
{

}

void MainWindow::on_actionCreate_project_triggered()
{
    QString dir_str = QFileDialog::getExistingDirectory(this, tr("Select"),"/home",QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(dir_str != NULL){
        string dir = dir_str.toStdString();
        ProjectManager *pm = new ProjectManager(ui->file_manager);
        pm->NewProjectMenu(dir);
    } else {
        cout << "[Error] Folder isn't selected!" << endl;
    }
}
