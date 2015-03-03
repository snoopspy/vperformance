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
// VPerformanceElapsedTimer_
// ----------------------------------------------------------------------------
namespace VPerformanceElapsedTimer_
{
  typedef int Milestone;

  typedef qint64 Clock;

  typedef qint64 Diff;

  struct Timer
  {
    QElapsedTimer elapsedTimer;
    Timer() { elapsedTimer.start(); }
    qint64 now() { return elapsedTimer.nsecsElapsed(); }
  };
}

// ----------------------------------------------------------------------------
// VPerformanceElapsedTimer
// ----------------------------------------------------------------------------
typedef VPerformance<
  VPerformanceElapsedTimer_::Milestone,
  VPerformanceElapsedTimer_::Clock,
  VPerformanceElapsedTimer_::Diff,
  VPerformanceElapsedTimer_::Timer
> VPerformanceElapsedTimer;

#endif // __V_PERFORMANCE_ELAPSEDTIMER_H__
