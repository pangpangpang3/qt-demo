#include <QtCore/QThread>
#include <QObject>
#include <QApplication>
#include <QDebug>

class ThreadTest : public QThread {
private:
    void run() {
        qDebug() << "ThreadTest" << currentThreadId();
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug() << "Main Thread:" << QThread::currentThreadId();

    ThreadTest threadTest;

    threadTest.start();
    QObject::connect(&threadTest, SIGNAL(finished()), &a, SLOT(quit()));

    return a.exec();
}
