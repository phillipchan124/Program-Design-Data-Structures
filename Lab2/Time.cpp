// Lab 2a, Writing Overloading Operators
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)

#include "Time.h"

// set hours
void Time::setHours(int hour)
{
  hours = hour;
}
// set minutes
void Time::setMinutes(int minute)
{
  minutes = minute;
}
// set seconds
void Time::setSeconds(int second)
{
  seconds = second;
}
// get time in hours
double Time::timeInHours() const
{
  double time;
  time = hours + minutes / 60.0 + seconds / 3600.0;
  return time;
}
// get time in minutes
double Time::timeInMinutes() const
{
  double time;
  time = hours * 60 + minutes + seconds / 60.0;
  return time;
}
// get time in seconds
double Time::timeInSeconds() const
{
  double time;
  time = hours * 3600 + minutes * 60 + seconds;
  return time;
}
// overloading operator <
bool operator<(const Time & t1, const Time & t2)
{
  double second1, second2;
  second1 = t1.timeInSeconds(); // convert t1 to second
  second2 = t2.timeInSeconds(); // convert t2 to second
  return second1 < second2;
}
// overloading operator ==
bool operator==(const Time & t1, const Time & t2)
{
  double second1, second2;
  second1 = t1.timeInSeconds(); // convert t1 to second
  second2 = t2.timeInSeconds(); // convert t2 to second
  return second1 == second2;
}
