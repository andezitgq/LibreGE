QT       += core gui opengl widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    editor/formeditor.cpp \
    editor/highlighter.cpp \
    glwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    project/create_project_form.cpp \
    project/filemanager.cpp \
    projectmanager.cpp

HEADERS += \
    editor/formeditor.h \
    editor/highlighter.h \
    glwidget.h \
    mainwindow.h \
    project/create_project_form.h \
    project/filemanager.h \
    projectmanager.h

FORMS += \
    editor/formeditor.ui \
    mainwindow.ui \
    project/create_project_form.ui

TRANSLATIONS += \
    LibreGE_en_US.ts

LIBS += -lGL -lGLU -lglut -ljsoncpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    src/icons.qrc
