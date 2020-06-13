#include <QMessageBox>
#include <iostream>
#include <string>
#include "projectmanager.h"
#include "create_project_form.h"
#include "ui_create_project_form.h"


using namespace std;
using std::string;

CreateProjectForm::CreateProjectForm(ProjectManager *pm, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CreateProjectForm)
{
    ui->setupUi(this);
    this->pm = pm;

    ui->comboType->addItem("First Person");
    ui->comboType->addItem("Third Person");
    ui->comboType->addItem("Empty");
}

CreateProjectForm::~CreateProjectForm()
{
    delete ui;
}

void CreateProjectForm::on_createButton_released()
{
    if(ui->projectName->text() != NULL){
        if(ui->mainSceneName->text() != NULL){
            this->pm->CreateProject(ui->projectName->text().toStdString(),
                             ui->mainSceneName->text().toStdString(),
                             ui->comboType->currentText().toStdString());

            QMessageBox msgBox;
            string msgText = "Project '" + ui->projectName->text().toStdString() + "' created!";
            QString QMsgText = QString::fromStdString(msgText);
            msgBox.setText(QMsgText);
            msgBox.setWindowTitle("Completed!");
            msgBox.setIcon(QMessageBox::Information);
            msgBox.exec();

            this->close();
        } else {
            QMessageBox msgBox;
            msgBox.setText("Enter main scene name!");
            msgBox.setWindowTitle("Error");
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.exec();
        }
    } else {
        QMessageBox msgBox;
        msgBox.setText("Enter project name!");
        msgBox.setWindowTitle("Error");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
    }
}
