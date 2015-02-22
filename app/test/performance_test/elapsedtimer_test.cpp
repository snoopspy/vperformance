#include <VPerformanceElapsedTimer>
#include "mytest.h"

TEST (ElapsedTimer, loopTest)
{
  MyTest<VPerformanceElapsedTimer, MY_TEST_LOOP_CNT, Loop>();
}

TEST (ElapsedTimer, noneTest)
{
  MyTest<VPerformanceElapsedTimer, MY_TEST_LOOP_CNT, None>();
}

TEST (ElapsedTimer, usleepTest)
{
  MyTest<VPerformanceElapsedTimer, MY_TEST_LOOP_CNT, USleep>();
}

TEST (ElapsedTimer, msleepTest)
{
  MyTest<VPerformanceElapsedTimer, MY_TEST_LOOP_CNT, MSleep>();
}

TEST (ElapsedTimer, sleepTest)
{
  MyTest<VPerformanceElapsedTimer, 1, Sleep>();
}
