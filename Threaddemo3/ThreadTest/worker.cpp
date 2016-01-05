#include <QThread>
#include <QDebug>
#include "worker.h"

Worker::Worker()
{
}

void Worker::onTimeOut() {
    qDebug() << "worker from thread:" << QThread::currentThreadId();
}

Worker::~Worker() {}
