#ifndef TIMER_H
#define TIMER_H
#include <chrono>

class Timer
{
public: 
    using Nanos = std::chrono::nanoseconds;
    using Micros = std::chrono::microseconds;
    using Millis = std::chrono::milliseconds;
    using Seconds = std::chrono::seconds;
    using Minutes = std::chrono::minutes;
    using Hours = std::chrono::hours;

    //Default Constructor, timer1 running upon initialization. 
    Timer()
    {
        timer1 = std::chrono::steady_clock();
        lastRecord = timer1.now();
    }

    //Restart() function for the timer. 
    void restart()
    {
        timer1 = std::chrono::steady_clock();
        lastRecord = timer1.now();
    }

    //Click() function, updates last recorded time and returns time elapsed in T units. 
    template <typename T>
    uint64_t click()
    {
        auto newClick = timer1.now();
        uint64_t timeElapsed = std::chrono::duration_cast<T>(newClick - lastRecord).count();
        lastRecord = newClick;
        return timeElapsed;
    }

    //Glance() function, returns time elapsed in T units. 
    template <typename T>
    uint64_t glance() const
    {
        auto newClick = timer1.now();
        uint64_t timeElapsed = std::chrono::duration_cast<T>(newClick - lastRecord).count();
        return timeElapsed;
    }

private: 
    std::chrono::steady_clock timer1;
    std::chrono::time_point<std::chrono::steady_clock> lastRecord;
};


#endif  // TIMER_H
