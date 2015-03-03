// ----------------------------------------------------------------------------
//
// VDream Component Suite version 9.1
//
// http://www.gilgil.net
//
// Copyright (c) Gilbert Lee All rights reserved
//
// ----------------------------------------------------------------------------

#ifndef __V_PERFORMANCE_GET_TICK_COUNT_H__
#define __V_PERFORMANCE_GET_TICK_COUNT_H__

#if defined(WIN32) || defined(_WIN32)

#include <windows.h>
#include "vperformance.h"

// ----------------------------------------------------------------------------
// VPerformanceGetTickCount_
// ----------------------------------------------------------------------------
namespace VPerformanceGetTickCount_
{
  typedef int Milestone;

  typedef DWORD Clock;

  typedef DWORD Diff;

  struct Timer
  {
    Clock now() { return GetTickCount(); }
  };
}

// ----------------------------------------------------------------------------
// VPerformanceGetTickCount
// ----------------------------------------------------------------------------
typedef VPerformance<
  VPerformanceGetTickCount_::Milestone,
  VPerformanceGetTickCount_::Clock,
  VPerformanceGetTickCount_::Diff,
  VPerformanceGetTickCount_::Timer
> VPerformanceGetTickCount;

#endif // WIN32

#endif // __V_PERFORMANCE_GET_TICK_COUNT_H__
