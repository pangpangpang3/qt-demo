#include <QApplication>
#include <QDebug>

#include "threadtest.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug() << "Main thread:" << QThread::currentThreadId();

    ThreadTest threadTest;
    threadTest.start();
    return a.exec();
}
