#include <QtCore/QThread>
#include <QtCore/QMutex>
#include <QtCore/QMutexLocker>
#include <QObject>
#include <QApplication>
#include <QDebug>
#include <QPushButton>
#include <QObject>

class ThreadTest : public QThread {
    Q_OBJECT
public:
    ThreadTest():m_stop(false) {
    }
public slots:
    void stop() {
        qDebug() << "Stop The Thread from:" << currentThreadId();
        QMutexLocker locker(&m_mutex);
        m_stop = true;
    }
private:
    QMutex m_mutex;
    bool m_stop;
    void run() {
        qDebug() << "ThreadTest from work thread:" << currentThreadId();
        while(1) {
            {
                QMutexLocker lock(&m_mutex);
                if(m_stop) break;
            }
            msleep(10);
        }
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug() << "Main Thread:" << QThread::currentThreadId();
    QPushButton stopButton("Stop Thread");
    ThreadTest threadTest;

    threadTest.start();
    stopButton.show();
    QObject::connect(&stopButton, SIGNAL(clicked()), &threadTest, SLOT(stop()));
    QObject::connect(&threadTest, SIGNAL(finished()), &a, SLOT(quit()));

    return a.exec();
}
