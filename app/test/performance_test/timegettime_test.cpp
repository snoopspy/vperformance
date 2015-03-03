#if defined(WIN32) || defined(_WIN32)

#include <VPerformanceTimeGetTime>
#include "mytest.h"

TEST(TimeGetTime, test)
{
  MyTest<VPerformanceTimeGetTime>();
}

#endif // WIN32
