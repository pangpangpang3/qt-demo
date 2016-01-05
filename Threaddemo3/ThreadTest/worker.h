#ifndef WORKER
#define WORKER

#include <QObject>

class Worker:public QObject
{
    Q_OBJECT
public:
    Worker();
    ~Worker();
public slots:
    void onTimeOut();
};
#endif // WORKER

