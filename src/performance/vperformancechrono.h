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

// ----------------------------------------------------------------------------
// VPerformanceChrono
// ----------------------------------------------------------------------------
class VPerformanceChrono
  : public VPerformance<
      int, // MILESTONE
      std::chrono::high_resolution_clock::time_point, // CLOCK
      std::chrono::high_resolution_clock::duration, // DIFF
      std::chrono::high_resolution_clock // TIMER
    > {};

std::ostream& operator << (std::ostream& os, std::chrono::high_resolution_clock::duration& rhs)
{
  os << rhs.count();
  return os;
}

#endif // __V_PERFORMANCE_CHRONO_H__

