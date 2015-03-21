#ifdef _WIN32

#include <VPerformanceGetTickCount>
#include "mytest.h"

TEST(GetTickCount, test)
{
  MyTest<VPerformanceGetTickCount>();
}

#endif // _WIN32
