#ifndef CREATE_PROJECT_FORM_H
#define CREATE_PROJECT_FORM_H

#include <QMainWindow>
#include <string>
#include "projectmanager.h"

namespace Ui {
class CreateProjectForm;
}

class CreateProjectForm : public QMainWindow
{
    Q_OBJECT

public:
    ProjectManager *pm;
    explicit CreateProjectForm(ProjectManager *pm, QWidget *parent = nullptr);
    ~CreateProjectForm();

private slots:
    void on_createButton_released();

private:
    Ui::CreateProjectForm *ui;
};

#endif // CREATE_PROJECT_FORM_H
