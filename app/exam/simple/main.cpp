#include <iostream>
#include <unistd.h>
#include <VPerformanceChrono>

void doSomething(int msec)
{
  usleep(msec * 1000);
}

int main()
{
  VPerformanceChrono pf;
  for (int i = 0; i < 10; i++)
  {
    pf.check(__LINE__);
    doSomething(10);
    pf.check(__LINE__);
    doSomething(20);
    pf.check(__LINE__);
    doSomething(30);
    pf.check(__LINE__);
    doSomething(40);
    pf.check(__LINE__);
    doSomething(50);
  }
  pf.report(std::cout);
}
