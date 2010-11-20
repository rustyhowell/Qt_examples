#ifndef __SleeperThread_h__
#define __SleeperThread_h__

#include <QThread>


class SleeperThread : public QThread
{
    public:
        static void msleep(unsigned long msecs)
        {
            QThread::msleep(msecs);
        }
};


#endif
