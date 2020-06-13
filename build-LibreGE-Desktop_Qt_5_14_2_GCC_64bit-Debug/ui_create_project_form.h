/********************************************************************************
** Form generated from reading UI file 'create_project_form.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATE_PROJECT_FORM_H
#define UI_CREATE_PROJECT_FORM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateProjectForm
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *projectName;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *mainSceneName;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QComboBox *comboType;
    QFrame *line;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *createButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancelButton;

    void setupUi(QMainWindow *CreateProjectForm)
    {
        if (CreateProjectForm->objectName().isEmpty())
            CreateProjectForm->setObjectName(QString::fromUtf8("CreateProjectForm"));
        CreateProjectForm->setWindowModality(Qt::ApplicationModal);
        CreateProjectForm->resize(360, 512);
        CreateProjectForm->setMinimumSize(QSize(360, 512));
        CreateProjectForm->setMaximumSize(QSize(360, 512));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/favicon/LibreGE_Favicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        CreateProjectForm->setWindowIcon(icon);
        centralwidget = new QWidget(CreateProjectForm);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        projectName = new QLineEdit(centralwidget);
        projectName->setObjectName(QString::fromUtf8("projectName"));

        horizontalLayout->addWidget(projectName);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(label_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        mainSceneName = new QLineEdit(centralwidget);
        mainSceneName->setObjectName(QString::fromUtf8("mainSceneName"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mainSceneName->sizePolicy().hasHeightForWidth());
        mainSceneName->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(mainSceneName);


        horizontalLayout_3->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_5->addWidget(label_4);

        comboType = new QComboBox(centralwidget);
        comboType->setObjectName(QString::fromUtf8("comboType"));
        sizePolicy1.setHeightForWidth(comboType->sizePolicy().hasHeightForWidth());
        comboType->setSizePolicy(sizePolicy1);
        comboType->setEditable(false);

        horizontalLayout_5->addWidget(comboType);


        verticalLayout->addLayout(horizontalLayout_5);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        createButton = new QPushButton(centralwidget);
        createButton->setObjectName(QString::fromUtf8("createButton"));

        horizontalLayout_4->addWidget(createButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        cancelButton = new QPushButton(centralwidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout_4->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout_4);

        CreateProjectForm->setCentralWidget(centralwidget);

        retranslateUi(CreateProjectForm);

        QMetaObject::connectSlotsByName(CreateProjectForm);
    } // setupUi

    void retranslateUi(QMainWindow *CreateProjectForm)
    {
        CreateProjectForm->setWindowTitle(QCoreApplication::translate("CreateProjectForm", "New Project", nullptr));
        label->setText(QCoreApplication::translate("CreateProjectForm", "Project name", nullptr));
        label_3->setText(QCoreApplication::translate("CreateProjectForm", "Main scene name", nullptr));
        label_4->setText(QCoreApplication::translate("CreateProjectForm", "Type", nullptr));
        comboType->setCurrentText(QString());
        createButton->setText(QCoreApplication::translate("CreateProjectForm", "Create", nullptr));
        cancelButton->setText(QCoreApplication::translate("CreateProjectForm", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateProjectForm: public Ui_CreateProjectForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATE_PROJECT_FORM_H
