VDream Performance Measurement Library
======================================

# About
* VPerformance is a simple and robust template based time difference measurement library for C++.

# Install
* VPerformance consists of only header files, and it requires no library build for using.
    * For Qt user(based on **QElapsedTimer**)
      * Include **vperformance.pri**.
    * For None Qt user(based on **chrono**)
      * Just include and use header files in src folder.

# Examples
* See the following code. Suppose that it contains a critical routine that consumes too much time. You don't know which function is time comsuming. Anyway, you would like to figure out how long it takes time in each routine. In this case, VPerformance is a good solution for the problem.

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

* Let me add a code using **VPerformance** module.

```cpp
#include <VPerformanceChrono> // Add header file

void doSomething(int msec)
{
  std::this_thread::sleep_for(std::chrono::milliseconds(msec));
}

int main()
{
  VPerformanceChrono pfm; // Declare object of the class
  for (int i = 0; i < 10; i++)
  {
    pfm.check(1111); // Call check everywhere you would like to check time consuming
    doSomething(10);
    pfm.check(2222);
    doSomething(20);
    pfm.check(3333);
    doSomething(30);
    pfm.check(4444);
    doSomething(40);
  }
  pfm.report(); // Call report to see the result
}
```

* The result. You get count, elapsed and average time information(nano-second) where check function is called.
  
```
beg     end     count   elapsed      average
1111    2222    10      101,155,750  10,115,575
2222    3333    10      201,018,290  20,101,829
3333    4444    10      301,024,734  30,102,473
4444    1111    9       360,927,856  40,103,095
```

* For more information, see [exam](app/exam/) and [test](app/test/) codes.

# Author
* [Gilbert Lee](http://www.gilgil.net)

# License
* [GNU GENERAL PUBLIC LICENSE](http://www.gnu.org/copyleft/gpl.html)
