#include <QThread>
#include "vperformance.h"

int main()
{
  VPerformance pfm;

  for (int i = 0; i < 5; i++)
  {
    pfm.check(__LINE__);
    QThread::msleep(100);
    pfm.check(__LINE__);
    QThread::msleep(100);
    pfm.check(__LINE__);
    QThread::msleep(100);
    pfm.check(__LINE__);
    QThread::msleep(100);
    pfm.check(__LINE__);
    QThread::msleep(100);
  }
  pfm.report();
}
