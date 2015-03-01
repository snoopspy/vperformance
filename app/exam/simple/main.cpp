#include <chrono>
#include <thread>
#include <VPerformanceChrono>

int main()
{
  VPerformanceChrono pfm(__LINE__);
  std::this_thread::sleep_for(std::chrono::seconds(1));
  pfm.check(__LINE__);
}

