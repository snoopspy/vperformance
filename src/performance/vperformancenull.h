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

namespace Null
{
  typedef int64_t MyInt;

  struct Milestone
  {
    MyInt _m;

    Milestone()                                   { _m = 0;              }
    Milestone(const int rhs)                      { _m = rhs;            }
    bool operator <  (const Milestone& rhs) const { return _m < rhs._m;  }
    bool operator >  (const Milestone& rhs) const { return _m > rhs._m;  }
    bool operator == (const Milestone& rhs) const { return _m == rhs._m; }
    bool operator != (const Milestone& rhs) const { return _m != rhs._m; }
  };

  struct Clock
  {
    MyInt _c;

    Clock operator - (const Clock &rhs) const { Clock res; res._c = _c - rhs._c; return res; }
  };

  struct Diff
  {
    MyInt _d;

    Diff operator += (const Clock &rhs)   { _d += rhs._c; return *this;              }
    Diff operator / (const int rhs) const { Diff res; res._d = _d / rhs; return res; }
  };

  struct Timer
  {
    MyInt _t;

    Clock now() { Clock res; res._c = _t++; return res; }
  };
};

std::ostream& operator << (std::ostream& os, Null::Milestone& rhs)
{
  os << rhs._m;
  return os;
}

std::ostream& operator << (std::ostream& os, Null::Diff& rhs)
{
  os << rhs._d;
  return os;
}

// ----------------------------------------------------------------------------
// VPerformanceNull
// ----------------------------------------------------------------------------
class VPerformanceNull
  : public VPerformance<Null::Milestone, Null::Clock, Null::Diff, Null::Timer> {};

#endif // __V_PERFORMANCE_NULL_H__