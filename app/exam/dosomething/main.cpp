#include <chrono>
#include <thread>
#include <VPerformanceChrono>

void doSomething(int msec)
{
  std::this_thread::sleep_for(std::chrono::milliseconds(msec));
}

int main()
{
  VPerformanceChrono pfm;
  for (int i = 0; i < 10; i++)
  {
    pfm.check(__LINE__);
    doSomething(10);
    pfm.check(__LINE__);
    doSomething(20);
    pfm.check(__LINE__);
    doSomething(30);
    pfm.check(__LINE__);
    doSomething(40);
  }
  pfm.report();
}
