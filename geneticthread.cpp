#include "geneticthread.h"

void GeneticThread::run()
{
    this->przebieg=0;
    this->started=0;

    QTimer timer;
    connect(&timer, SIGNAL(timeout()), this, SLOT(timerHit()), Qt::DirectConnection);
    timer.setInterval(50);
    timer.start();   // puts one event in the threads event queue
    exec();
    timer.stop();
}

void GeneticThread::timerHit()
{
    if(this->started==1) {
        emit sendTime(++this->przebieg);
    }
}

void GeneticThread::startToggle()
{
    if(this->started==1) {
        this->started=0;
    } else {
        this->started=1;
    }
}
