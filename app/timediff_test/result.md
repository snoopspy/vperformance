|         |                              | Resolution            | Executing cost | Diffing cost | Result             |
|---------|------------------------------|-----------------------|----------------|--------------|--------------------|
| Windows | GetTickCount()               | msec                  | ?              | ?            | ?                  |
|         | timeGetTime()                | ?                     | ?              | ?            | ?                  |
| Linux   | clock()                      | sec                   | Too slow       | Fast         | Bad resolution     |
|         | gettimeofday()               | usec                  | Fast           | Fast         | Good               |
|         | time()                       | sec                   | Fast           | Fast         | Bad resolution     |
| C++11   | system_clock::now()          | msec, usec, nsec, ... | Fast           | Slow         | Bad diffing cost   |
|         | high_resolution_clock::now() | msec, usec, nsec      | Fast           | Slow         | Bad diffing cost   |
| Qt      | QTime::elapsed()             | msec                  | Too slow       | Fast         | Bad executing cost |
|         | QElapsedTimer::elapsed()     | msec, nsec            | Fast           | Fast         | Good               |
