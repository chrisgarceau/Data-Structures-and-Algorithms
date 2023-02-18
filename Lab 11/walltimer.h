/*
 * walltimer.h
 *
 *  Created on: Dec 5, 2015
 *  Updated Spring 2018 with chrono dependancy
 *      Author: S. Miller
 */

#ifndef WALLTIMER_H_
#define WALLTIMER_H_

#include <string>


/*
 *  A simple timer class to see how long a piece of code takes.
 *  Usage:
 *
 *  {
 *      static WallTimer timer();
 *
 *      ...
 *
 *      timer.start()
 *      [ The code you want timed ]
 *      timer.stop()
 *
 *      ...
 *  }
 *
 *  At the end of execution, you will call
 *  	timer.elapsed_seconds() to return the # of elapsed seconds
 *
 */


#if __cplusplus <= 199711L
#ifdef _WIN32
#include <Windows.h>
#else
#include <sys/time.h>
#endif
//1997 C++ code
class WallTimer
{
public:
    WallTimer(bool start_running=false) : _accum(0), _running(false)
    {
        if (start_running) start();
    }

    ~WallTimer() { stop(); }

    void start() {
        if (!_running) {
            _start_time = GetTimeMicroseconds();
            _running = true;
        }
    }

    void stop() {
        if (_running) {
            unsigned long long stop_time = GetTimeMicroseconds();
            _accum += stop_time - _start_time;
            _running = false;
        }
    }

    int get_minutes() {
    	return elapsed_seconds() / 60;
    }

    double get_seconds() {
    	return elapsed_seconds() - get_minutes()*60;
    }

    double elapsed_seconds() {
        //return static_cast<long long>(_accum / 1.e6);
        return (_accum / 1.e6);
    }

private:
    // cf. http://stackoverflow.com/questions/1861294/how-to-calculate-execution-time-of-a-code-snippet-in-c
    unsigned long long GetTimeMicroseconds() {
#ifdef _WIN32
        /* Windows */
        FILETIME ft;
        LARGE_INTEGER li;

        /* Get the amount of 100 nano seconds intervals elapsed since January 1, 1601 (UTC) and copy it
         *   * to a LARGE_INTEGER structure. */
        GetSystemTimeAsFileTime(&ft);
        li.LowPart = ft.dwLowDateTime;
        li.HighPart = ft.dwHighDateTime;

        unsigned long long ret = li.QuadPart;
        ret -= 116444736000000000LL; /* Convert from file time to UNIX epoch time. */
        ret /= 10; /* From 100 nano seconds (10^-7) to 1 microsecond (10^-6) intervals */
#else
        /* Linux */
        struct timeval tv;

        gettimeofday(&tv, nullptr);

        unsigned long long ret = tv.tv_usec;
        /* Adds the seconds (10^0) after converting them to microseconds (10^-6) */
        ret += (tv.tv_sec * 1000000);
#endif
        return ret;
    }
    long long _accum;
    unsigned long long _start_time;
    bool _running;
};

#else
//Newer C++11 code
#include <chrono>
#include <cstdint>

class WallTimer
{
public:
    explicit WallTimer(bool start_running=false)
    {
    	isActive = false;
    	if (start_running) start();
    }

    ~WallTimer() { stop(); }

    void start() {
        if (!isActive ) {
        	startTime = std::chrono::high_resolution_clock::now();
        	isActive = true;
        }
    }

    void stop() {
        if (isActive) {
            stopTime  =  std::chrono::high_resolution_clock::now();
            isActive = false;
        }
    }

    int get_minutes() {
    	return static_cast<int>(elapsed_seconds() / 60);
    }

    double get_seconds() {
    	return elapsed_seconds() - get_minutes()*60;
    }

    double elapsed_seconds() {
    	int64_t elapsed_nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(stopTime - startTime).count();
        return elapsed_nanoseconds / 1000000000.0;
    }

private:
    std::chrono::high_resolution_clock::time_point startTime;
    std::chrono::high_resolution_clock::time_point stopTime;
    bool isActive;
};

#endif


#endif /* WALLTIMER_H_ */
