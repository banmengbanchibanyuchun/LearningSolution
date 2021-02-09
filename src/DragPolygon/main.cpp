#include "mainwindow.h"

#include <QApplication>
#include <form.h>
#include <AngleRectView.h>
#include <drawtext.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    Form f;
    f.show();

    AngleRectView angle(NULL);
    angle.show();

    DrawText drawtext;
    drawtext.show();

    return a.exec();
}
