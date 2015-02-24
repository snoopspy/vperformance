#ifndef MYTEST_H
#define MYTEST_H

#include <gtest/gtest.h>
#include <iostream>

template <class PERFORMANCE, int LOOP_CNT = 1000000>
struct MyTest
{
  MyTest()
  {
    PERFORMANCE pf;
    for (int i = 0; i < LOOP_CNT; i++)
    {
      pf.check(1);
      pf.check(2);
      pf.check(3);
      pf.check(4);
      pf.check(5);
      pf.check(6);
      pf.check(7);
      pf.check(8);
      pf.check(9);
      pf.check(10);
      pf.check(11);
      pf.check(12);
      pf.check(13);
      pf.check(14);
      pf.check(15);
      pf.check(16);
      pf.check(17);
      pf.check(18);
      pf.check(19);
      pf.check(20);
      pf.check(21);
      pf.check(22);
      pf.check(23);
      pf.check(24);
      pf.check(25);
      pf.check(26);
      pf.check(27);
      pf.check(28);
      pf.check(29);
      pf.check(30);
      pf.check(31);
      pf.check(32);
    }
    pf.report(std::cout);
  }
};

#endif // MYTEST_H
