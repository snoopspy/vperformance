// ----------------------------------------------------------------------------
//
// VDream Component Suite version 9.1
//
// http://www.gilgil.net
//
// Copyright (c) Gilbert Lee All rights reserved
//
// ----------------------------------------------------------------------------

#ifndef __V_PERFORMANCE_ELAPSEDTIMER_H__
#define __V_PERFORMANCE_ELAPSEDTIMER_H__

#include <QElapsedTimer>
#include "vperformance.h"

// ----------------------------------------------------------------------------
// VPerformanceElapsedTimerTimer
// ----------------------------------------------------------------------------
struct VPerformanceElapsedTimerTimer
{
  QElapsedTimer elapsedTimer;
  VPerformanceElapsedTimerTimer() { elapsedTimer.start(); }
  qint64 now() { return elapsedTimer.nsecsElapsed(); }
};

typedef
  VPerformance<
    int, // MILESTONE
    qint64, // CLOCK
    qint64, // DIFF
    VPerformanceElapsedTimerTimer // TIMER
  > VPerformanceElapsedTimer;

#endif // __V_PERFORMANCE_ELAPSEDTIMER_H__
