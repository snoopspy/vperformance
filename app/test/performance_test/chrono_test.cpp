#include <VPerformanceChrono>
#include "mytest.h"

TEST (Chrono, noneTest)
{
  MyTest<VPerformanceChrono, None>();
}

TEST (Chrono, loopTest)
{
  MyTest<VPerformanceChrono, Loop>();
}

TEST (Chrono, usleepTest)
{
  MyTest<VPerformanceChrono, USleep>();
}

TEST (Chrono, msleepTest)
{
  MyTest<VPerformanceChrono, MSleep>();
}

TEST (Chrono, sleepTest)
{
  MyTest<VPerformanceChrono, Sleep, 1>();
}
