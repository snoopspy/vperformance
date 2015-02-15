#include <iostream>

static const int LOOP_CNT = 10000000;

#ifdef __linux__
// ----------------------------------------------------------------------------
// linux
// ----------------------------------------------------------------------------
#include <time.h>
void test_clock_usec()
{
  clock_t beg = clock();
  clock_t end;
  clock_t diff;
  for (int i = 0; i < LOOP_CNT; i++)
  {
    end = clock();
    diff = end - beg;
  }
  std::cout << diff * 1000 / CLOCKS_PER_SEC << "\t" << __func__ << std::endl;
}

#include <sys/time.h>
void test_gettimeofday_usec()
{
  struct timeval beg; gettimeofday(&beg, NULL);
  struct timeval end;
  __suseconds_t diff;
  for (int i = 0; i < LOOP_CNT; i++)
  {
    gettimeofday(&end, NULL);
    diff = (end.tv_sec - beg.tv_sec) * 1000000 + (end.tv_usec - beg.tv_usec);
  }
  std::cout << diff / 1000 << "\t" << __func__ << std::endl;
}

#include <time.h>
void test_time_sec()
{
  time_t beg; time(&beg);
  time_t end;
  time_t diff;
  for (int i = 0; i < LOOP_CNT; i++)
  {
    time(&end);
    diff = end - beg;
  }
  std::cout << diff * 1000 << "\t" << __func__ << std::endl;
}
#endif // __linux__

// ----------------------------------------------------------------------------
// c++11
// ----------------------------------------------------------------------------
#include <chrono>
void test_system_clock_msec()
{
  using namespace std::chrono;

  system_clock::time_point beg = system_clock::now();
  system_clock::time_point end;
  milliseconds diff;
  for (int i = 0; i < LOOP_CNT; i++)
  {
    end = system_clock::now();
    diff = duration_cast<milliseconds>(end - beg);
  }
  std::cout << diff.count() << "\t" << __func__ << std::endl;
}

#include <chrono>
void test_system_clock_usec()
{
  using namespace std::chrono;

  system_clock::time_point beg = system_clock::now();
  system_clock::time_point end;
  microseconds diff;
  for (int i = 0; i < LOOP_CNT; i++)
  {
    end = system_clock::now();
    diff = duration_cast<microseconds>(end - beg);
  }
  std::cout << diff.count() / 1000 << "\t" << __func__ << std::endl;
}

#include <chrono>
void test_system_clock_nsec()
{
  using namespace std::chrono;

  system_clock::time_point beg = system_clock::now();
  system_clock::time_point end;
  nanoseconds diff;
  for (int i = 0; i < LOOP_CNT; i++)
  {
    end = system_clock::now();
    diff = duration_cast<nanoseconds>(end - beg);
  }
  std::cout << diff.count() / 1000000 << "\t" << __func__ << std::endl;
}

#include <chrono>
void test_high_resolution_clock_msec()
{
  using namespace std::chrono;

  high_resolution_clock::time_point beg = high_resolution_clock::now();
  high_resolution_clock::time_point end;
  milliseconds diff;
  for (int i = 0; i < LOOP_CNT; i++)
  {
    end = high_resolution_clock::now();
    diff = duration_cast<milliseconds>(end - beg);
  }
  std::cout << diff.count() << "\t" << __func__ << std::endl;
}

#include <chrono>
void test_high_resolution_clock_usec()
{
  using namespace std::chrono;

  high_resolution_clock::time_point beg = high_resolution_clock::now();
  high_resolution_clock::time_point end;
  microseconds diff;
  for (int i = 0; i < LOOP_CNT; i++)
  {
    end = high_resolution_clock::now();
    diff = duration_cast<microseconds>(end - beg);
  }
  std::cout << diff.count() / 1000 << "\t" << __func__ << std::endl;
}

#include <chrono>
void test_high_resolution_clock_nsec()
{
  using namespace std::chrono;

  high_resolution_clock::time_point beg = high_resolution_clock::now();
  high_resolution_clock::time_point end;
  nanoseconds diff;
  for (int i = 0; i < LOOP_CNT; i++)
  {
    end = high_resolution_clock::now();
    diff = duration_cast<nanoseconds>(end - beg);
  }
  std::cout << diff.count() / 1000000 << "\t" << __func__ << std::endl;
}

// ----------------------------------------------------------------------------
// qt
// ----------------------------------------------------------------------------
#include <QTime>
void test_qtime_msec()
{
  QTime time;
  time.start();

  int beg = time.elapsed();
  int end;
  int diff;
  for (int i = 0; i < LOOP_CNT; i++)
  {
    end = time.elapsed();
    diff = end - beg;
  }
  std::cout << diff << "\t" << __func__ << std::endl;
}

#include <QElapsedTimer>
void test_qelapsedtimer_msec()
{
  QElapsedTimer elapsedTimer;
  elapsedTimer.start();

  quint64 beg = elapsedTimer.elapsed();
  quint64 end;
  quint64 diff;
  for (int i = 0; i < LOOP_CNT; i++)
  {
    end = elapsedTimer.elapsed();
    diff = end - beg;
  }
  std::cout << diff << "\t" << __func__ << std::endl;
}

#include <QElapsedTimer>
void test_qelapsedtimer_nsec()
{
  QElapsedTimer elapsedTimer;
  elapsedTimer.start();

  quint64 beg = elapsedTimer.nsecsElapsed();
  quint64 end;
  quint64 diff;
  for (int i = 0; i < LOOP_CNT; i++)
  {
    end = elapsedTimer.nsecsElapsed();
    diff = end - beg;
  }
  std::cout << diff /1000000 << "\t" << __func__ << std::endl;
}

// ----------------------------------------------------------------------------
// main
// ----------------------------------------------------------------------------
int main()
{
#ifdef __linux__
  //
  // linux
  //
  test_clock_usec();
  test_time_sec();
  test_gettimeofday_usec();
#endif // __linux__

  //
  // c++11
  //
  test_system_clock_msec();
  test_system_clock_usec();
  test_system_clock_nsec();
  test_high_resolution_clock_msec();
  test_high_resolution_clock_usec();
  test_high_resolution_clock_nsec();

  //
  // qt
  //
  test_qtime_msec();
  test_qelapsedtimer_msec();
  test_qelapsedtimer_nsec();
}
