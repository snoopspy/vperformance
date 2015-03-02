// ----------------------------------------------------------------------------
//
// VDream Component Suite version 9.1
//
// http://www.gilgil.net
//
// Copyright (c) Gilbert Lee All rights reserved
//
// ----------------------------------------------------------------------------

#ifndef __V_PERFORMANCE_GET_TIME_OF_DAY_H__
#define __V_PERFORMANCE_GET_TIME_OF_DAY_H__

#include <sys/time.h>
#include "vperformance.h"

// ----------------------------------------------------------------------------
// VPerformanceGetTimeOfDay
// ----------------------------------------------------------------------------
typedef VPerformance<
  int, // MILESTONE
  std::chrono::high_resolution_clock::time_point, // CLOCK
  std::chrono::high_resolution_clock::duration, // DIFF
  std::chrono::high_resolution_clock // TIMER
> VPerformanceChrono;

std::ostream& operator << (std::ostream& os, std::chrono::high_resolution_clock::duration& rhs)
{
  os << rhs.count();
  return os;
}

#endif // __V_PERFORMANCE_GET_TIME_OF_DAY_H__
