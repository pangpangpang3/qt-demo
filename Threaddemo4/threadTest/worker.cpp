#include <QThread>
#include <QDebug>

#include "worker.h"

Worker::Worker()
{
}

void Worker::onTimeOut() {
    qDebug() << "The worker from thread:" << QThread::currentThreadId();
}

Worker::~Worker()
{

}
