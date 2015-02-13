#include "vperformance.h"
#include <stdio.h> // for printf gilgil temp

// ----------------------------------------------------------------------------
// VPerformance
// ----------------------------------------------------------------------------
VPerformance::VPerformance()
{
  verbose = false;
  clear();
}

VPerformance::~VPerformance()
{
  clear();
}

void VPerformance::clear()
{
  verboseList.clear();
  reportMap.clear();
  lastMilestone = 0;
  elapsedTimer.start();
  lastClock = elapsedTimer.elapsed();
}

void VPerformance::check(int milestone)
{
  check(milestone, elapsedTimer.elapsed());
}

void VPerformance::check(int milestone, int64_t now)
{
  if (verbose)
  {
    Verbose verbose;
    verbose.from = lastMilestone;
    verbose.to = milestone;
    verbose.elapsed = now - lastClock;
    verboseList.push_back(verbose);
  } else
  {
    ReportKey key;
    key.from = lastMilestone;
    key.to = milestone;

    ReportData &data = reportMap[key];
    data.count++;
    data.totalElapsed += now - lastClock;
  }
  lastMilestone = milestone;
  lastClock      = now;
}

#define log printf // gilgil temp
void VPerformance::report()
{
  if (verbose)
  {
    log("beg\tend\tduration\n");
    foreach (const Verbose& verbose, verboseList)
    {
      if (verbose.from == 0) continue;
      log("%d\t%d\t%lld\n", verbose.from, verbose.to, verbose.elapsed);
    }
  } else
  {
    log("beg\tend\tcount\tduration\n");
    for (ReportMap::iterator it = reportMap.begin(); it != reportMap.end(); it++)
    {
      ReportKey key = it->first;
      if (key.from == 0) continue;
      ReportData data = it->second;
      log("%d\t%d\t%d\t%lld\n", key.from, key.to, data.count, data.totalElapsed);
    }
  }
}
