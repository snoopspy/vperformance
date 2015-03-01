VDream Performance Measurement Library
======================================

# Needs
  * There exists the following code.
```
  doSometing1();
  doSometing2();
  doSometing3();
  doSometing4();
```
  * Suppoose that it contains a critical routine that consume too much time. You don't know which function is time comsuming, and you would like to figure out how long it takes time in in each routine. VPerformance is a google solution for this problem.

# Example
  * Here is a original code.
```
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
```
#include <VPerformanceChrono> /**/
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
  * Call **check** function everywhere you would like to check time consuming job. You'd better use __LINC__ macro for parameter.
  * At last, call "report" function to write the result.
```
int main()
{
  VPerformanceChrono pfm;
  for (int i = 0; i < 10; i++)
  {
    pfm.check(__LINE__); /**/
    doSomething(10);
    pfm.check(__LINE__); /**/
    doSomething(20);
    pfm.check(__LINE__); /**/
    doSomething(30);
    pfm.check(__LINE__); /**/
    doSomething(40);
  }
  pfm.report();
}
```
  * You can get the following result.
```
beg	end	count	elapsed	average
15	17	10	160,341,449	16,034,144
17	19	10	293,037,016	29,303,701
19	21	10	313,344,209	31,334,420
21	15	9	414,471,311	46,052,367
```
# About


# Install

# Use

# Example

# References


