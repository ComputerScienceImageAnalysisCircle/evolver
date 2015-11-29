#include <QtGui/QApplication>
#include "mainwindow.h"
#include <stdlib.h>
#include <time.h>
#include <geneticthread.h>
#include <QDebug>

int main(int argc, char *argv[])
{

    srand(time(NULL));

    QApplication a(argc, argv);
    MainWindow w;

    GeneticThread geneticThread;
    QObject::connect(&geneticThread, SIGNAL(sendTime(int)), &w, SLOT(update(int)), Qt::QueuedConnection);
    QObject::connect(&w, SIGNAL(start()), &geneticThread, SLOT(startToggle()), Qt::QueuedConnection);
    geneticThread.start();
    w.show();
    a.exec();
    geneticThread.quit();
    geneticThread.wait();

    return 0;
}
