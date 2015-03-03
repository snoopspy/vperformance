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

#include <map>
#include <iostream>
#include <assert.h>

// ----------------------------------------------------------------------------
// VPerformance
// ----------------------------------------------------------------------------
/*
 * MILESTONE (e.g. int)
 * CLOCK     (e.g. std::chrono::high_resolution_clock::time_point)
 * DIFF      (e.g. std::chrono::high_resolution_clock::duration)
 * TIMER     (e.g. std::chrono::high_resolution_clock)
 *
 * For more information, see VPerformanceNull
 */
template <typename MILESTONE, typename CLOCK, typename DIFF, class TIMER>
class VPerformance
{
  struct Key
  {
    MILESTONE from;
    MILESTONE to;

    bool operator < (const Key& rhs) const
    {
      if (this->from < rhs.from) return true;
      if (this->from > rhs.from) return false;
      if (this->to < rhs.to) return true;
      return false;
    }

    bool operator == (const Key& rhs) const
    {
      return (from == rhs.from) && (to == rhs.to);
    }

    struct Hash
    {
      size_t operator()(const Key &key) const
      {
        return std::hash<MILESTONE>()(key.from) ^ std::hash<MILESTONE>()(key.to);
      }
    };
  };

  struct Data
  {
  public:
    int count;
    DIFF totalElapsed;
  };

  typedef std::map<Key, Data> ReportMap;

public:
  TIMER timer;
  ReportMap reportMap;
  MILESTONE lastMilestone;
  CLOCK lastClock;

public:
  VPerformance(MILESTONE startMilestone = 0)
  {
    clear();
    if (startMilestone != 0)
      check(startMilestone);
  }

  virtual ~VPerformance()
  {
    if (reportMap.size() > 0)
      report(true);
  }

  void clear()
  {
    reportMap.clear();
    lastMilestone = 0;
    lastClock = timer.now();
  }

  void check(MILESTONE milestone)
  {
    check(milestone, timer.now());
  }

  void check(MILESTONE milestone, CLOCK now)
  {
    Key key;
    key.from = lastMilestone;
    key.to = milestone;

    Data &data = reportMap[key];
    data.count++;
    data.totalElapsed += DIFF(now - lastClock);

    lastMilestone = milestone;
    lastClock = now;
  }

  virtual void report(bool autoClear = true, std::ostream* os = NULL)
  {
    if (os == NULL) os = &std::cout;
    os->imbue(std::locale(""));
    *os << "beg\tend\tcount\telapsed\taverage\n";
    for (auto it = reportMap.begin(); it != reportMap.end(); it++)
    {
      Key key = it->first;
      if (key.from == 0) continue;
      Data data = it->second;
      assert(data.count != 0);
      DIFF avg = data.totalElapsed / data.count;
      *os << key.from
        << "\t" << key.to
        << "\t" << data.count
        << "\t" << data.totalElapsed
        << "\t" << avg
        << std::endl;
    }
    if (autoClear) clear();
  }
};

#endif // __V_PERFORMANCE_H__
