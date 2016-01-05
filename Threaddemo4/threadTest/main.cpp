#include <QApplication>
#include <QTimer>
#include <QThread>
#include <QDebug>

#include "worker.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qDebug() << "Main thread:" << QThread::currentThreadId();
    QThread thread;
    QTimer timer;
    Worker worker;
    timer.start(100);
    QObject::connect(&timer, SIGNAL(timeout()), &worker, SLOT(onTimeOut()));

//    timer.moveToThread(&thread);
    worker.moveToThread(&thread);
    thread.start();
    return a.exec();
}
