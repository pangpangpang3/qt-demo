#ifndef THREADTEST_H
#define THREADTEST_H

#include <QThread>

class ThreadTest : public QThread
{
    Q_OBJECT

public:
    ThreadTest();
    ~ThreadTest();
public slots:
    void run();
};

#endif // WIDGET_H
