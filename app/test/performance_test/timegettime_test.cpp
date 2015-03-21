#ifdef _WIN32

#include <VPerformanceTimeGetTime>
#include "mytest.h"

TEST(TimeGetTime, test)
{
  MyTest<VPerformanceTimeGetTime>();
}

#endif // _WIN32
