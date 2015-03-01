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
    pfm.check(1111); /**/
    doSomething(10);
    pfm.check(2222); /**/
    doSomething(20);
    pfm.check(3333); /**/
    doSomething(30);
    pfm.check(4444); /**/
    doSomething(40);
  }
  pfm.report();
}
