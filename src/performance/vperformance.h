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
// #include <unordered_map> // gilgil temp 2015.02.22
#include <ostream>

/*
 * MILESTONE : int
 *
 * CLOCK     : std::chrono::high_resolution_clock::time_point
 *
 * ELAPSED   : std::chrono::nanoseconds
 *
 * TIMER     : show have the following functions
 *   void clear();
 *   CLOCK now();
 *
 * */
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
  //typedef std::unordered_map<ReportKey, ReportData, ReportKey::Hash> ReportMap; // gilgil temp 2015.02.22

public:
  TIMER timer;
  ReportMap reportMap;
  MILESTONE lastMilestone;
  CLOCK lastClock;

public:
  VPerformance()          { clear(); }
  virtual ~VPerformance() { clear(); }

  void clear()
  {
    timer.clear();
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
    data.totalElapsed += now - lastClock;

    lastMilestone = milestone;
    lastClock = now;
  }

  virtual void report(std::ostream& os)
  {
    os << "beg\tend\tcount\telapsed\taverage\n";
    for (auto it = reportMap.begin(); it != reportMap.end(); it++)
    {
      Key key = it->first;
      if (key.from == 0) continue;
      Data data = it->second;
      int avg = (int)data.totalElapsed / data.count;
      os << key.from
        << "\t" << key.to
        << "\t" << data.count
        << "\t" << data.totalElapsed
        << "\t" << avg
        << std::endl;
    }
  }
};

#endif // __V_PERFORMANCE_H__
