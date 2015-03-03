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
// VPerformanceChrono_
// ----------------------------------------------------------------------------
namespace VPerformanceChrono_
{
  typedef int Milestone;

  typedef std::chrono::high_resolution_clock::time_point Clock;

  typedef std::chrono::high_resolution_clock::duration Diff;

  typedef std::chrono::high_resolution_clock Timer;
};

// ----------------------------------------------------------------------------
// VPerformanceChrono
// ----------------------------------------------------------------------------
typedef VPerformance<
  VPerformanceChrono_::Milestone,
  VPerformanceChrono_::Clock,
  VPerformanceChrono_::Diff,
  VPerformanceChrono_::Timer
> VPerformanceChrono;

std::ostream& operator << (std::ostream& os, std::chrono::high_resolution_clock::duration& rhs)
{
  os << rhs.count();
  return os;
}

#endif // __V_PERFORMANCE_CHRONO_H__
