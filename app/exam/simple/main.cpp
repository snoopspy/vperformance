#include <iostream>
#include <unistd.h>
#include <VPerformanceChrono>

int main()
{
  VPerformanceChrono pf;
  pf.check(1973);
  usleep(1000000);
  pf.check(2015);
  pf.report(std::cout);
}
