// ----------------------------------------------------------------------------
//
// VDream Component Suite version 9.1
//
// http://www.gilgil.net
//
// Copyright (c) Gilbert Lee All rights reserved
//
// ----------------------------------------------------------------------------

#ifndef __V_PERFORMANCE_TIME_GET_TIME_H__
#define __V_PERFORMANCE_TIME_GET_TIME_H__

#ifdef _WIN32

#include <windows.h>
#include "vperformance.h"

// ----------------------------------------------------------------------------
// VPerformanceTimeGetTime_
// ----------------------------------------------------------------------------
namespace VPerformanceTimeGetTime_
{
  typedef int Milestone;

  typedef DWORD Clock;

  typedef DWORD Diff;

  struct Timer
  {
    Clock now() { return timeGetTime(); }
  };
}

// ----------------------------------------------------------------------------
// VPerformanceTimeGetTime
// ----------------------------------------------------------------------------
typedef VPerformance<
  VPerformanceTimeGetTime_::Milestone,
  VPerformanceTimeGetTime_::Clock,
  VPerformanceTimeGetTime_::Diff,
  VPerformanceTimeGetTime_::Timer
> VPerformanceTimeGetTime;

#endif // _WIN32

#endif // __V_PERFORMANCE_TIME_GET_TIME_H__
