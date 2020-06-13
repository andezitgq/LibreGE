/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "glwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionOpen_project;
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *actionRecent_files;
    QAction *actionExit;
    QAction *actionBuild_settings;
    QAction *actionProject_settings;
    QAction *actionCreate_project;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    GLWidget *GLwidget;
    QTabWidget *right_tabs;
    QWidget *hierarchy_tab;
    QHBoxLayout *horizontalLayout;
    QListView *listView;
    QWidget *inspector;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QPushButton *openEditor;
    QTabWidget *bottom_tabs;
    QWidget *files_tab;
    QGridLayout *gridLayout_2;
    QListWidget *file_manager;
    QWidget *terminal_tab;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *terminal;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuBuild;
    QMenu *menuDebug;
    QMenu *menuWindow;
    QMenu *menuSupport;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(960, 540);
        MainWindow->setMinimumSize(QSize(960, 540));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/favicon/LibreGE_Favicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionOpen_project = new QAction(MainWindow);
        actionOpen_project->setObjectName(QString::fromUtf8("actionOpen_project"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        actionRecent_files = new QAction(MainWindow);
        actionRecent_files->setObjectName(QString::fromUtf8("actionRecent_files"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionBuild_settings = new QAction(MainWindow);
        actionBuild_settings->setObjectName(QString::fromUtf8("actionBuild_settings"));
        actionProject_settings = new QAction(MainWindow);
        actionProject_settings->setObjectName(QString::fromUtf8("actionProject_settings"));
        actionCreate_project = new QAction(MainWindow);
        actionCreate_project->setObjectName(QString::fromUtf8("actionCreate_project"));
        actionCreate_project->setCheckable(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/favicon/LibreGE_Favicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCreate_project->setIcon(icon1);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        GLwidget = new GLWidget(centralwidget);
        GLwidget->setObjectName(QString::fromUtf8("GLwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GLwidget->sizePolicy().hasHeightForWidth());
        GLwidget->setSizePolicy(sizePolicy);
        GLwidget->setMinimumSize(QSize(0, 0));
        GLwidget->setCursor(QCursor(Qt::CrossCursor));
        GLwidget->setAutoFillBackground(true);

        gridLayout->addWidget(GLwidget, 0, 0, 1, 1);

        right_tabs = new QTabWidget(centralwidget);
        right_tabs->setObjectName(QString::fromUtf8("right_tabs"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(7);
        sizePolicy1.setHeightForWidth(right_tabs->sizePolicy().hasHeightForWidth());
        right_tabs->setSizePolicy(sizePolicy1);
        right_tabs->setMinimumSize(QSize(0, 0));
        right_tabs->setMovable(true);
        hierarchy_tab = new QWidget();
        hierarchy_tab->setObjectName(QString::fromUtf8("hierarchy_tab"));
        horizontalLayout = new QHBoxLayout(hierarchy_tab);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        listView = new QListView(hierarchy_tab);
        listView->setObjectName(QString::fromUtf8("listView"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(listView->sizePolicy().hasHeightForWidth());
        listView->setSizePolicy(sizePolicy2);
        listView->setLineWidth(1);

        horizontalLayout->addWidget(listView);

        right_tabs->addTab(hierarchy_tab, QString());
        inspector = new QWidget();
        inspector->setObjectName(QString::fromUtf8("inspector"));
        verticalLayout = new QVBoxLayout(inspector);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableView = new QTableView(inspector);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setShowGrid(true);
        tableView->setGridStyle(Qt::CustomDashLine);

        verticalLayout->addWidget(tableView);

        openEditor = new QPushButton(inspector);
        openEditor->setObjectName(QString::fromUtf8("openEditor"));

        verticalLayout->addWidget(openEditor);

        right_tabs->addTab(inspector, QString());

        gridLayout->addWidget(right_tabs, 0, 1, 1, 1);

        bottom_tabs = new QTabWidget(centralwidget);
        bottom_tabs->setObjectName(QString::fromUtf8("bottom_tabs"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(3);
        sizePolicy3.setHeightForWidth(bottom_tabs->sizePolicy().hasHeightForWidth());
        bottom_tabs->setSizePolicy(sizePolicy3);
        bottom_tabs->setMinimumSize(QSize(0, 0));
        bottom_tabs->setAutoFillBackground(false);
        bottom_tabs->setStyleSheet(QString::fromUtf8(""));
        bottom_tabs->setMovable(true);
        files_tab = new QWidget();
        files_tab->setObjectName(QString::fromUtf8("files_tab"));
        files_tab->setCursor(QCursor(Qt::ArrowCursor));
        gridLayout_2 = new QGridLayout(files_tab);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        file_manager = new QListWidget(files_tab);
        file_manager->setObjectName(QString::fromUtf8("file_manager"));
        file_manager->setViewMode(QListView::IconMode);
        file_manager->setItemAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout_2->addWidget(file_manager, 0, 0, 1, 1);

        bottom_tabs->addTab(files_tab, QString());
        terminal_tab = new QWidget();
        terminal_tab->setObjectName(QString::fromUtf8("terminal_tab"));
        horizontalLayout_2 = new QHBoxLayout(terminal_tab);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        terminal = new QTextEdit(terminal_tab);
        terminal->setObjectName(QString::fromUtf8("terminal"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(terminal->sizePolicy().hasHeightForWidth());
        terminal->setSizePolicy(sizePolicy4);
        terminal->setStyleSheet(QString::fromUtf8("background:black; color:white;"));
        terminal->setReadOnly(true);

        horizontalLayout_2->addWidget(terminal);

        bottom_tabs->addTab(terminal_tab, QString());

        gridLayout->addWidget(bottom_tabs, 1, 0, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 960, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuBuild = new QMenu(menubar);
        menuBuild->setObjectName(QString::fromUtf8("menuBuild"));
        menuDebug = new QMenu(menubar);
        menuDebug->setObjectName(QString::fromUtf8("menuDebug"));
        menuWindow = new QMenu(menubar);
        menuWindow->setObjectName(QString::fromUtf8("menuWindow"));
        menuSupport = new QMenu(menubar);
        menuSupport->setObjectName(QString::fromUtf8("menuSupport"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuBuild->menuAction());
        menubar->addAction(menuDebug->menuAction());
        menubar->addAction(menuWindow->menuAction());
        menubar->addAction(menuSupport->menuAction());
        menuFile->addAction(actionCreate_project);
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionOpen_project);
        menuFile->addAction(actionRecent_files);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_as);
        menuFile->addSeparator();
        menuFile->addAction(actionProject_settings);
        menuFile->addAction(actionBuild_settings);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);

        retranslateUi(MainWindow);

        right_tabs->setCurrentIndex(1);
        bottom_tabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "LibreGE", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "New scene", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open scene", nullptr));
        actionOpen_project->setText(QCoreApplication::translate("MainWindow", "Open project", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionSave_as->setText(QCoreApplication::translate("MainWindow", "Save as...", nullptr));
        actionRecent_files->setText(QCoreApplication::translate("MainWindow", "Recent files", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionBuild_settings->setText(QCoreApplication::translate("MainWindow", "Build settings", nullptr));
        actionProject_settings->setText(QCoreApplication::translate("MainWindow", "Project settings", nullptr));
        actionCreate_project->setText(QCoreApplication::translate("MainWindow", "Create project", nullptr));
        right_tabs->setTabText(right_tabs->indexOf(hierarchy_tab), QCoreApplication::translate("MainWindow", "Hierarchy", nullptr));
        openEditor->setText(QCoreApplication::translate("MainWindow", "Open Editor", nullptr));
        right_tabs->setTabText(right_tabs->indexOf(inspector), QCoreApplication::translate("MainWindow", "Inspector", nullptr));
        bottom_tabs->setTabText(bottom_tabs->indexOf(files_tab), QCoreApplication::translate("MainWindow", "Files", nullptr));
        bottom_tabs->setTabText(bottom_tabs->indexOf(terminal_tab), QCoreApplication::translate("MainWindow", "Terminal", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuBuild->setTitle(QCoreApplication::translate("MainWindow", "Build", nullptr));
        menuDebug->setTitle(QCoreApplication::translate("MainWindow", "Tools", nullptr));
        menuWindow->setTitle(QCoreApplication::translate("MainWindow", "Window", nullptr));
        menuSupport->setTitle(QCoreApplication::translate("MainWindow", "Support", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
