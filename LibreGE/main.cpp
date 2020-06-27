#include <QApplication>
#include <GL/glut.h>

#include "mainwindow.h"
#include "project/filemanager.h"

using namespace std;

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
