// Lab 1b, More Class Programming and Testing
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)

#ifndef _Time_h
#define _Time_h

class Time
{
private:
  int hours;
  int minutes;
  int seconds;
public:
  void setHours(int hours); // setter
  void setMinutes(int minutes); // setter
  void setSeconds(int seconds); // setter
  double timeInHours() const; // get time in hours
  double timeInMinutes() const; // get time in minutes
  double timeInSeconds() const; // get time in seconds
};

#endif
