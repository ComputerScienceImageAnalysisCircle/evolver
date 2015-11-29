#ifndef GENETICTHREAD_H
#define GENETICTHREAD_H

#include <QThread>
#include <QTimer>
#include <QDateTime>

class GeneticThread : public QThread
{
    Q_OBJECT
signals:
    void sendTime(int time);

private:
    void run();
    QString m_lastTime;
    int przebieg;
    int started;


public slots:
    void startToggle();

private slots:
    void timerHit();
};

#endif // GENETICTHREAD_H
