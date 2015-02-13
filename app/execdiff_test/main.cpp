#include <iostream>
#include <unistd.h> // for sleep

static const int LOOP_CNT1 = 1000;
static const int LOOP_CNT2 = 1000;

// ----------------------------------------------------------------------------
// test_none
// ----------------------------------------------------------------------------
void test_none()
{
  int beg = 0;
  int end;
  int diff;
  for (int i = 0; i < LOOP_CNT1; i++)
  {
    for (int j = 0; j < LOOP_CNT2; j++)
    {
      end = 0;
      diff = end - beg;
    }
  }
  std::cout << diff  << "\t" << __func__ << std::endl;
}

// ----------------------------------------------------------------------------
// test_clock_sec
// ----------------------------------------------------------------------------
#include <time.h>
void test_clock_sec()
{
  clock_t beg = clock();
  clock_t end;
  clock_t diff;
  for (int i = 0; i < LOOP_CNT1; i++)
  {
    for (int j = 0; j < LOOP_CNT2; j++)
    {
      end = clock();
      diff = end - beg;
    }
  }
  std::cout << diff  << "\t" << __func__ << std::endl;
}

// ----------------------------------------------------------------------------
// test_gettimeofday_usec
// ----------------------------------------------------------------------------
#include <sys/time.h>
void test_gettimeofday_usec()
{
  struct timeval beg; gettimeofday(&beg, NULL);
  struct timeval end;
  __suseconds_t diff;
  for (int i = 0; i < LOOP_CNT1; i++)
  {
    for (int j = 0; j < LOOP_CNT2; j++)
    {
      gettimeofday(&end, NULL);
      diff = (end.tv_sec - beg.tv_sec) * 1000000 + (end.tv_usec - beg.tv_usec);
    }
  }
  std::cout << diff  << "\t" << __func__ << std::endl;
}

// ----------------------------------------------------------------------------
// test_time_sec
// ----------------------------------------------------------------------------
#include <time.h>
void test_time_sec()
{
  time_t beg; time(&beg);
  time_t end;
  time_t diff;
  for (int i = 0; i < LOOP_CNT1; i++)
  {
    for (int j = 0; j < LOOP_CNT2; j++)
    {
      time(&end);
      diff = end - beg;
    }
  }
  std::cout << diff  << "\t" << __func__ << std::endl;
}

// ----------------------------------------------------------------------------
// test_system_clock_msec
// ----------------------------------------------------------------------------
#include <chrono>
void test_system_clock_msec()
{
  using namespace std::chrono;

  system_clock::time_point beg = system_clock::now();
  system_clock::time_point end;
  milliseconds diff;
  for (int i = 0; i < LOOP_CNT1; i++)
  {
    for (int j = 0; j < LOOP_CNT2; j++)
    {
      end = system_clock::now();
      diff = duration_cast<milliseconds>(end - beg);
    }
  }
  std::cout << diff.count() << "\t" << __func__ << std::endl;
}

// ----------------------------------------------------------------------------
// test_system_clock_usec
// ----------------------------------------------------------------------------
#include <chrono>
void test_system_clock_usec()
{
  using namespace std::chrono;

  system_clock::time_point beg = system_clock::now();
  system_clock::time_point end;
  microseconds diff;
  for (int i = 0; i < LOOP_CNT1; i++)
  {
    for (int j = 0; j < LOOP_CNT2; j++)
    {
      end = system_clock::now();
      diff = duration_cast<microseconds>(end - beg);
    }
  }
  std::cout << diff.count() << "\t" << __func__ << std::endl;
}

// ----------------------------------------------------------------------------
// test_system_clock_nsec
// ----------------------------------------------------------------------------
#include <chrono>
void test_system_clock_nsec()
{
  using namespace std::chrono;

  system_clock::time_point beg = system_clock::now();
  system_clock::time_point end;
  nanoseconds diff;
  for (int i = 0; i < LOOP_CNT1; i++)
  {
    for (int j = 0; j < LOOP_CNT2; j++)
    {
      end = system_clock::now();
      diff = duration_cast<nanoseconds>(end - beg);
    }
  }
  std::cout << diff.count() << "\t" << __func__ << std::endl;
}

// ----------------------------------------------------------------------------
// test_high_resolution_clock_msec
// ----------------------------------------------------------------------------
#include <chrono>
void test_high_resolution_clock_msec()
{
  using namespace std::chrono;

  high_resolution_clock::time_point beg = high_resolution_clock::now();
  high_resolution_clock::time_point end;
  milliseconds diff;
  for (int i = 0; i < LOOP_CNT1; i++)
  {
    for (int j = 0; j < LOOP_CNT2; j++)
    {
      end = high_resolution_clock::now();
      diff = duration_cast<milliseconds>(end - beg);
    }
  }
  std::cout << diff.count()  << "\t" << __func__ << std::endl;
}

// ----------------------------------------------------------------------------
// test_high_resolution_clock_usec
// ----------------------------------------------------------------------------
#include <chrono>
void test_high_resolution_clock_usec()
{
  using namespace std::chrono;

  high_resolution_clock::time_point beg = high_resolution_clock::now();
  high_resolution_clock::time_point end;
  microseconds diff;
  for (int i = 0; i < LOOP_CNT1; i++)
  {
    for (int j = 0; j < LOOP_CNT2; j++)
    {
      end = high_resolution_clock::now();
      diff = duration_cast<microseconds>(end - beg);
    }
  }
  std::cout << diff.count()  << "\t" << __func__ << std::endl;
}


// ----------------------------------------------------------------------------
// test_high_resolution_clock_nsec
// ----------------------------------------------------------------------------
#include <chrono>
void test_high_resolution_clock_nsec()
{
  using namespace std::chrono;

  high_resolution_clock::time_point beg = high_resolution_clock::now();
  high_resolution_clock::time_point end;
  nanoseconds diff;
  for (int i = 0; i < LOOP_CNT1; i++)
  {
    for (int j = 0; j < LOOP_CNT2; j++)
    {
      end = high_resolution_clock::now();
      diff = duration_cast<nanoseconds>(end - beg);
    }
  }
  std::cout << diff.count()  << "\t" << __func__ << std::endl;
}

// ----------------------------------------------------------------------------
// test_qtime_msec
// ----------------------------------------------------------------------------
#include <QTime>
void test_qtime_msec()
{
  QTime time;
  time.start();
  int beg = time.elapsed();
  int end;
  int diff;
  for (int i = 0; i < LOOP_CNT1; i++)
  {
    for (int j = 0; j < LOOP_CNT2; j++)
    {
      end = time.elapsed();
      diff = end - beg;
    }
  }
  std::cout << diff  << "\t" << __func__ << std::endl;
}

// ----------------------------------------------------------------------------
// test_qelapsedtimer_msec
// ----------------------------------------------------------------------------
#include <QElapsedTimer>
void test_qelapsedtimer_msec()
{
  QElapsedTimer elapsedTimer;
  elapsedTimer.start();
  quint64 beg = elapsedTimer.elapsed();
  quint64 end;
  quint64 diff;
  for (int i = 0; i < LOOP_CNT1; i++)
  {
    for (int j = 0; j < LOOP_CNT2; j++)
    {
      end = elapsedTimer.elapsed();
      diff = end - beg;
    }
  }
  std::cout << diff  << "\t" << __func__ << std::endl;
}

// ----------------------------------------------------------------------------
// test_qelapsedtimer_nsec
// ----------------------------------------------------------------------------
#include <QElapsedTimer>
void test_qelapsedtimer_nsec()
{
  QElapsedTimer elapsedTimer;
  elapsedTimer.start();
  quint64 beg = elapsedTimer.nsecsElapsed();
  quint64 end;
  quint64 diff;
  for (int i = 0; i < LOOP_CNT1; i++)
  {
    for (int j = 0; j < LOOP_CNT2; j++)
    {
      end = elapsedTimer.nsecsElapsed();
      diff = end - beg;
    }
  }
  std::cout << diff  << "\t" << __func__ << std::endl;
}

// ----------------------------------------------------------------------------
// main
// ----------------------------------------------------------------------------
int main()
{
  test_none();

  //test_clock_sec();
  test_time_sec();
  test_gettimeofday_usec();

  test_system_clock_msec();
  test_system_clock_usec();
  test_system_clock_nsec();

  test_high_resolution_clock_msec();
  test_high_resolution_clock_usec();
  test_high_resolution_clock_nsec();

  test_qtime_msec();
  test_qelapsedtimer_msec();
  test_qelapsedtimer_nsec();
}
