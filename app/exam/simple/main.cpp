#include <chrono>
#include <thread>
#include <VPerformanceChrono>

int main()
{
  VPerformanceChrono pf(__LINE__);
  std::this_thread::sleep_for(std::chrono::seconds(1));
  pf.check(__LINE__);
}

