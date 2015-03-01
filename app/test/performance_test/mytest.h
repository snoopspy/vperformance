#ifndef MYTEST_H
#define MYTEST_H

#include <gtest/gtest.h>
#include <iostream>

template <class PERFORMANCE, int LOOP_CNT = 100000>
struct MyTest
{
  MyTest()
  {
    PERFORMANCE pfm;
    for (int i = 0; i < LOOP_CNT; i++)
    {
      pfm.check(1);
      pfm.check(2);
      pfm.check(3);
      pfm.check(4);
      pfm.check(5);
      pfm.check(6);
      pfm.check(7);
      pfm.check(8);
      pfm.check(9);
      pfm.check(10);
      pfm.check(11);
      pfm.check(12);
      pfm.check(13);
      pfm.check(14);
      pfm.check(15);
      pfm.check(16);
      pfm.check(17);
      pfm.check(18);
      pfm.check(19);
      pfm.check(20);
      pfm.check(21);
      pfm.check(22);
      pfm.check(23);
      pfm.check(24);
      pfm.check(25);
      pfm.check(26);
      pfm.check(27);
      pfm.check(28);
      pfm.check(29);
      pfm.check(30);
      pfm.check(31);
      pfm.check(32);
    }
    pfm.report(std::cout);
  }
};

#endif // MYTEST_H
