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
  typedef int Milestone;

  typedef long /*__suseconds_t*/ Diff;

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
  VPerformanceGetTimeOfDay_::Milestone,
  VPerformanceGetTimeOfDay_::Clock,
  VPerformanceGetTimeOfDay_::Diff,
  VPerformanceGetTimeOfDay_::Timer
> VPerformanceGetTimeOfDay;

#endif // __V_PERFORMANCE_GET_TIME_OF_DAY_H__
