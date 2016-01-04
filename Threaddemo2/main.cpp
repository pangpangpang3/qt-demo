#include <QtCore/QThread>
#include <QtCore/QMutex>
#include <QtCore/QMutexLocker>
#include <QObject>
#include <QApplication>
#include <QDebug>
#include <QPushButton>
#include <QObject>

#include "threadtest.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug() << "Main Thread:" << QThread::currentThreadId();
    QPushButton stopButton("Stop Thread");
    ThreadTest threadTest;

    threadTest.start();
    stopButton.show();
    QObject::connect(&stopButton, SIGNAL(clicked()), &threadTest, SLOT(stop()));
    QObject::connect(&threadTest, SIGNAL(finished()), &a, SLOT(quit()));

    return a.exec();
}
