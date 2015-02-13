// ----------------------------------------------------------------------------
//
// VDream Component Suite version 9.1
//
// http://www.gilgil.net
//
// Copyright (c) Gilbert Lee All rights reserved
//
// ----------------------------------------------------------------------------

#ifndef __V_PERFORMANCE_H__
#define __V_PERFORMANCE_H__

#include <list>
#include <map>
#include <stdint.h>

// ----------------------------------------------------------------------------
// VPerformance
// ----------------------------------------------------------------------------
class VPerformance
{
  struct Verbose
  {
    int from;
    int to;
    int64_t elapsed;
  };

  typedef std::list<Verbose> VerboseList;

  struct ReportKey
  {
    int from;
    int to;
    bool operator < (const ReportKey& rhs) const
    {
      if (this->from < rhs.from) return true;
      if (this->from > rhs.from) return false;
      if (this->to < rhs.to) return true;
      return false;
    }
  };

  struct ReportData
  {
  public:
    int count;
    int64_t totalElapsed;
  };

  typedef std::map<ReportKey, ReportData> ReportMap;

public:
  VPerformance();
  virtual ~VPerformance();

public:
  bool verbose;
  VerboseList verboseList;
  ReportMap reportMap;

protected:
  int lastMilestone;
  int64_t lastClock;

public:
  void clear();
  void check(int milestone);
  void check(int milestone, int64_t now);
  void report();
};

#endif // __V_PERFORMANCE_H__
