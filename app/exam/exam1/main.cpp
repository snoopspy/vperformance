#include <unistd.h>
#include "vperformance.h"

void doSomething(int duration)
{
  usleep(duration);
}

int main()
{
  VPerformance pfm;

  for (int i = 0; i < 5; i++)
  {
    pfm.check(__LINE__);
    doSomething(100);
    pfm.check(__LINE__);
    doSomething(100);
    pfm.check(__LINE__);
    doSomething(100);
    pfm.check(__LINE__);
    doSomething(100);
    pfm.check(__LINE__);
    doSomething(100);
  }
  pfm.report();
}
