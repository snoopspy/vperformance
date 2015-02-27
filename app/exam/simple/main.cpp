#include <unistd.h>
#include <VPerformanceChrono>

int main()
{
  VPerformanceChrono pf(__LINE__);
  usleep(1000000);
  pf.check(__LINE__);
}
