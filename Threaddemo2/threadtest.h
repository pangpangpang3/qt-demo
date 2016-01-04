#ifndef THREADTEST
#define THREADTEST
#include <QThread>
#include <QMutex>

class ThreadTest: public QThread
{
    Q_OBJECT
public:
    ThreadTest();
    ~ThreadTest();
public slots:
    void stop();
private:
    QMutex m_mutex;
    bool m_stop;
    void run();

};
#endif // THREADTEST

