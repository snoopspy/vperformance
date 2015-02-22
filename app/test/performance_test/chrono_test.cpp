#include <VPerformanceChrono>
#include "mytest.h"

TEST (Chrono, loopTest)
{
  MyTest<VPerformanceChrono, MY_TEST_LOOP_CNT, Loop>();
}

TEST (Chrono, noneTest)
{
  MyTest<VPerformanceChrono, MY_TEST_LOOP_CNT, None>();
}

TEST (Chrono, usleepTest)
{
  MyTest<VPerformanceChrono, MY_TEST_LOOP_CNT, USleep>();
}

TEST (Chrono, msleepTest)
{
  MyTest<VPerformanceChrono, MY_TEST_LOOP_CNT, MSleep>();
}

TEST (Chrono, sleepTest)
{
  MyTest<VPerformanceChrono, 1, Sleep>();
}
