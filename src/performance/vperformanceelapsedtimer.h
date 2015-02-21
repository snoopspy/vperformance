#ifndef VPERFORMANCEELAPSEDTIMER_H
#define VPERFORMANCEELAPSEDTIMER_H

#include <QElapsedTimer>
#include "vperformance.h"

class VPerformanceElapsedTimerTimer
{
protected:
  QElapsedTimer elapsedTimer;
public:
  VPerformanceElapsedTimerTimer() { clear(); }
public:
  void clear() { elapsedTimer.start(); }
  qint64 now() { return elapsedTimer.nsecsElapsed(); }
};

class VPerformanceElapsedTimer : public VPerformance<qint64, qint64, qint64, VPerformanceElapsedTimerTimer> {};

#endif // VPERFORMANCEELAPSEDTIMER_H
