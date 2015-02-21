// ----------------------------------------------------------------------------
//
// VDream Component Suite version 9.1
//
// http://www.gilgil.net
//
// Copyright (c) Gilbert Lee All rights reserved
//
// ----------------------------------------------------------------------------

#ifndef __V_PERFORMANCE_CHRONO_H__
#define __V_PERFORMANCE_CHRONO_H__

#include <chrono>
#include <ostream>
#include "vperformance.h"

class VPerformanceChronoDiff : std::chrono::nanoseconds
{
public:
  operator int() const
  {
    return (int)this->count();
  }
};

class VPerformanceChronoTimer
{
public:
  void clear() {}
  std::chrono::high_resolution_clock::time_point now() { return std::chrono::high_resolution_clock::now(); }
};

class VPerformanceChrono: public VPerformance<int, std::chrono::high_resolution_clock::time_point, VPerformanceChronoDiff, VPerformanceChronoTimer> {};
#endif // __V_PERFORMANCE_CHRONO_H__

