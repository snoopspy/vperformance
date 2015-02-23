#include <iostream>
#include <unistd.h>
#include <VPerformanceChrono>

int main()
{
  VPerformanceChrono pf;
  pf.check(1);
  usleep(1000000);
  pf.check(2);
  pf.report(std::cout);
}
