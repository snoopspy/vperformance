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

#include <chrono>
#include <list>
#include <map>

// ----------------------------------------------------------------------------
// VPerformance
// ----------------------------------------------------------------------------
class VPerformance
{
  struct Verbose
  {
    int from;
    int to;
    std::chrono::nanoseconds elapsed;
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
    std::chrono::nanoseconds totalElapsed;
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
  std::chrono::high_resolution_clock::time_point lastClock;

public:
  void clear();
  void check(int milestone);
  void check(int milestone, std::chrono::high_resolution_clock::time_point now);
  void report();
};

#endif // __V_PERFORMANCE_H__
