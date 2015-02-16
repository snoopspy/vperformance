#include "vperformance.h"

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
  lastClock = std::chrono::high_resolution_clock::now();
}

void VPerformance::check(int milestone)
{
  check(milestone, std::chrono::high_resolution_clock::now());
}

void VPerformance::check(int milestone, std::chrono::high_resolution_clock::time_point now)
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
  lastClock = now;
}

#include <iostream>
void VPerformance::report()
{
  if (verbose)
  {
    std::cout << "beg\tend\telapsed\n";
    for (VerboseList::iterator it = verboseList.begin(); it != verboseList.end(); it++)
    {
      Verbose verbose = *it;
      if (verbose.from == 0) continue;
      std::cout << verbose.from << "\t"
        << "\t" << verbose.to
        << "\t" << verbose.elapsed.count()
        << std::endl;
    }
  } else
  {
    std::cout << "beg\tend\tcount\telapsed\taverage\n";
    for (ReportMap::iterator it = reportMap.begin(); it != reportMap.end(); it++)
    {
      ReportKey key = it->first;
      if (key.from == 0) continue;
      ReportData data = it->second;
      std::chrono::nanoseconds avg = data.totalElapsed / data.count;
      std::cout << key.from
        << "\t" << key.to
        << "\t" << data.count
        << "\t" << data.totalElapsed.count() / 1000000
        << "\t" << avg.count() / 1000000
        << std::endl;
    }
  }
}
