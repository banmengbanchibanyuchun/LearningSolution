#include "mainwindow.h"

#include <fremless.h>


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    Fremless F;
    F.show();

    return a.exec();
}
