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
// VPerformanceGetTimeOfDay_
// ----------------------------------------------------------------------------
namespace VPerformanceGetTimeOfDay_
{
  typedef __suseconds_t Diff;

  struct Clock
  {
    struct timeval tv_;

    Diff operator - (const Clock &rhs) const
    {
      return (tv_.tv_sec - rhs.tv_.tv_sec) * 1000000 + (tv_.tv_usec - rhs.tv_.tv_usec);
    }
  };

  struct Timer
  {
    Clock now()
    {
      Clock res;
      gettimeofday(&res.tv_, NULL);
      return res;
    }
  };
};

// ----------------------------------------------------------------------------
// VPerformanceGetTimeOfDay
// ----------------------------------------------------------------------------
typedef VPerformance<
  int, // MILESTONE
  VPerformanceGetTimeOfDay_::Clock, // CLOCK
  VPerformanceGetTimeOfDay_::Diff, // DIFF
  VPerformanceGetTimeOfDay_::Timer // TIMER
> VPerformanceGetTimeOfDay;

/*
std::ostream& operator << (std::ostream& os, std::chrono::high_resolution_clock::duration& rhs)
{
  os << rhs.count();
  return os;
}
*/

#endif // __V_PERFORMANCE_GET_TIME_OF_DAY_H__
