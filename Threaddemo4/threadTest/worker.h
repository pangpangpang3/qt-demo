#ifndef Worker_H
#define Worker_H

#include <QObject>

class Worker : public QObject
{
    Q_OBJECT
public:
    Worker();
    ~Worker();
public slots:
    void onTimeOut();
};

#endif // Worker_H
