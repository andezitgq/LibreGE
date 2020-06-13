/********************************************************************************
** Form generated from reading UI file 'formeditor.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMEDITOR_H
#define UI_FORMEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormEditor
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTextEdit *codeEdit1;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuTools;
    QMenu *menuWindow;
    QMenu *menuSupport;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FormEditor)
    {
        if (FormEditor->objectName().isEmpty())
            FormEditor->setObjectName(QString::fromUtf8("FormEditor"));
        FormEditor->resize(897, 590);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/favicon/LibreGE_Favicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        FormEditor->setWindowIcon(icon);
        centralwidget = new QWidget(FormEditor);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        codeEdit1 = new QTextEdit(centralwidget);
        codeEdit1->setObjectName(QString::fromUtf8("codeEdit1"));

        horizontalLayout->addWidget(codeEdit1);

        FormEditor->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FormEditor);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 897, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        menuWindow = new QMenu(menubar);
        menuWindow->setObjectName(QString::fromUtf8("menuWindow"));
        menuSupport = new QMenu(menubar);
        menuSupport->setObjectName(QString::fromUtf8("menuSupport"));
        FormEditor->setMenuBar(menubar);
        statusbar = new QStatusBar(FormEditor);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        FormEditor->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuWindow->menuAction());
        menubar->addAction(menuSupport->menuAction());

        retranslateUi(FormEditor);

        QMetaObject::connectSlotsByName(FormEditor);
    } // setupUi

    void retranslateUi(QMainWindow *FormEditor)
    {
        FormEditor->setWindowTitle(QCoreApplication::translate("FormEditor", "Code Editor", nullptr));
        menuFile->setTitle(QCoreApplication::translate("FormEditor", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("FormEditor", "Edit", nullptr));
        menuTools->setTitle(QCoreApplication::translate("FormEditor", "Tools", nullptr));
        menuWindow->setTitle(QCoreApplication::translate("FormEditor", "Window", nullptr));
        menuSupport->setTitle(QCoreApplication::translate("FormEditor", "Support", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormEditor: public Ui_FormEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMEDITOR_H
