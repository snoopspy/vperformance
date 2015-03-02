// ----------------------------------------------------------------------------
//
// VDream Component Suite version 9.1
//
// http://www.gilgil.net
//
// Copyright (c) Gilbert Lee All rights reserved
//
// ----------------------------------------------------------------------------

#ifndef __V_PERFORMANCE_NULL_H__
#define __V_PERFORMANCE_NULL_H__

#include "vperformance.h"

// ----------------------------------------------------------------------------
// VPerformanceNull_
// ----------------------------------------------------------------------------
namespace VPerformanceNull_
{
  typedef int Milestone;

  struct Diff
  {
    int d_;

    Diff operator += (const Diff &rhs) { d_ += rhs.d_; return *this; }
    Diff operator / (const int count) const { Diff res; res.d_ = d_ / count; return res; }
  };

  struct Clock
  {
    int c_;

    Diff operator - (const Clock &rhs) const { Diff res; res.d_ = c_ - rhs.c_; return res; }
  };

  struct Timer
  {
    int t_;

    Clock now() { Clock res; res.c_ = t_++; return res; }
  };
};

std::ostream& operator << (std::ostream& os, VPerformanceNull_::Diff& rhs)
{
  os << rhs.d_;
  return os;
}

// ----------------------------------------------------------------------------
// VPerformanceNull
// ----------------------------------------------------------------------------
typedef VPerformance<
  VPerformanceNull_::Milestone, // MILESTONE
  VPerformanceNull_::Clock, // CLOCK
  VPerformanceNull_::Diff, // DIFF
  VPerformanceNull_::Timer // TIMER
> VPerformanceNull;

#endif // __V_PERFORMANCE_NULL_H__
