#include <QMutex>
#include <QMutexLocker>
#include <QDebug>

#include "threadtest.h"

ThreadTest::ThreadTest():
    m_stop(false)
{
}
void ThreadTest::stop() {
    qDebug() << "Stop The Thread from:" << currentThreadId();
    QMutexLocker locker(&m_mutex);
    m_stop = true;
}

void ThreadTest::run() {
    qDebug() << "ThreadTest from work thread:" << currentThreadId();
    while(1) {
        {
            QMutexLocker lock(&m_mutex);
            if(m_stop) break;
        }
        msleep(10);
    }
}

ThreadTest::~ThreadTest() {

}
