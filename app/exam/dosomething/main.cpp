#include <chrono>
#include <thread>
#include <VPerformanceChrono>

void doSomething(int msec)
{
  std::this_thread::sleep_for(std::chrono::milliseconds(msec));
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
  }
  pf.report();
}
