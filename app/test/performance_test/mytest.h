#ifndef MYTEST_H
#define MYTEST_H

#include <gtest/gtest.h>
#include <iostream>
#include <time.h>

struct None
{
  void doSomething(int n) { (void)n; }
};

extern int _sum;
struct Loop
{
  void doSomething(int n) { _sum = 0; for (int i = 0; i < n * 1000000; i++) _sum += i; }
};

struct USleep
{
  void doSomething(int n) { usleep(n); }
};

struct MSleep
{
  void doSomething(int n) { usleep(n * 1000); }
};

struct Sleep
{
  void doSomething(int n) { sleep(n); }
};

template <class PERFORMANCE, class FOO, int LOOP_CNT = 1000>
struct MyTest
{
  MyTest()
  {
    PERFORMANCE pf;
    FOO foo;
    for (int i = 0; i < LOOP_CNT; i++)
    {
      pf.check(1);
      foo.doSomething(1);
      pf.check(2);
      foo.doSomething(2);
      pf.check(3);
      foo.doSomething(3);
      pf.check(4);
      foo.doSomething(4);
    }
    pf.report(std::cout);
  }
};

#endif // MYTEST_H
