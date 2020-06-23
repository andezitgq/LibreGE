#include <QApplication>
#include <GL/glut.h>

#include "mainwindow.h"
#include "project/filemanager.h"

using namespace std;

void check_changes(const char *filePath);

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
