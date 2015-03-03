#if defined(WIN32) || defined(_WIN32)

#include <VPerformanceGetTickCount>
#include "mytest.h"

TEST(GetTickCount, test)
{
  MyTest<VPerformanceGetTickCount>();
}

#endif // WIN32
