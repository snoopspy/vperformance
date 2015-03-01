VDream Performance Measurement Library
======================================

# About
  * VPerformance is a template based time measurement library for C++.
  * It uses c++11 chrono module or QElapsedTimer class of Qt.

# Install
  * VPerformance consists of only header file that means it requires no compilation.
    * For Qt user
      * Include **vperformance.pri**
    * For None Qt user
      * Just include and use header files in src folder.

# Examples
  * There exists the following code.
  * Suppose that it contains a critical routine that consumes too much time. You don't know which function is time comsuming, Anyway, you would like to figure out how long it takes time in in each routine. VPerformance is a good solution for this problem.
```cpp
  doSometing1();
  doSometing2();
  doSometing3();
  doSometing4();
```
  * Original code.
```cpp
void doSomething(int msec)
{
  std::this_thread::sleep_for(std::chrono::milliseconds(msec));
}

int main()
{
  for (int i = 0; i < 10; i++)
  {
    doSomething(10);
    doSomething(20);
    doSomething(30);
    doSomething(40);
  }
}
```
  * Add **VPerformanceChrono** header file and declare object of the class.
```cpp
#include <VPerformanceChrono> /**/
...
int main()
{
  VPerformanceChrono pfm; /**/
  for (int i = 0; i < 10; i++)
  {
    doSomething(10);
    doSomething(20);
    doSomething(30);
    doSomething(40);
  }
}
```
  * Call **check** function everywhere you would like to check time consuming job. You could use ```__LINE__``` macro for the parameter.
  * At the end, call **report** function to see the result.
``` cpp
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
  pfm.report(); /**/
}
```
  * The result. You get count, elapsed and average time information(nano-second) where check function is called.
```
beg     end     count   elapsed         average
1,111   2,222   10      112,851,496     11,285,149
2,222   3,333   10      213,760,269     21,376,026
3,333   4,444   10      310,136,538     31,013,653
4,444   1,111   9       370,962,486     41,218,054
```

# Author
* [Gilbert Lee](http://www.gilgil.net)

# License
[GNU GENERAL PUBLIC LICENSE](http://www.gnu.org/copyleft/gpl.html)
