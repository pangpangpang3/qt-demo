#include <QTimer>

#include "threadtest.h"
#include "worker.h"
ThreadTest::ThreadTest()
{
}

void ThreadTest::run() {
    QTimer timer;
    Worker worker;
    connect(&timer, SIGNAL(timeout()), &worker, SLOT(onTimeOut()));

    timer.start(1000);
    exec();
}

ThreadTest::~ThreadTest()
{

}
