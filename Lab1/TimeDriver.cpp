// Lab 1b, More Class Programming and Testing
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)
#include <iostream>
using namespace std;

#include <cassert>

#include "Time.h"
#include "Time.h" // testing ifndef

int main()
{
  // print my name and this assignment's title
  cout << "Lab 1b, More Class Programming and Testing\n";
  cout << "Programmer: Kwun Hang Chan\n";
  cout << "Editor(s) used: Xcode\n";
  cout << "Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  Time time; // create Time object
  
  // set hour, minute and second for time
  time.setHours(1);
  time.setMinutes(40);
  time.setSeconds(30);
  
  // calculate the time in hour, minute and second
  double timeHours = time.timeInHours();
  double timeMinutes = time.timeInMinutes();
  double timeSeconds = time.timeInSeconds();
  
  // output expected result
  cout << "Expected result: " << endl
  << "Time in hour: 1.675" << endl
  << "Time in minute: 100.5" << endl
  << "Time in second: 6030" << endl;
  
  // output the result
  cout << "Actual result: " << endl
  << "Time in hour: " << timeHours << endl
  << "Time in minute: " << timeMinutes << endl
  << "Time in second: " << timeSeconds << endl;
  
  // assertion for time in hour, minute and second
  assert((timeHours <= 1.676) && (timeHours >= 1.674));
  assert( 100.5 == timeMinutes );
  assert( 6030 == timeSeconds );
  
  // object copy testing
  {
    cout << "\nCopied Object named as copy." << endl;
    const Time copy = time;  //declare copy of object
    
    // calculate the time in hour, minute and second using copy
    timeHours = copy.timeInHours();
    timeMinutes = copy.timeInMinutes();
    timeSeconds = copy.timeInSeconds();
    
    // output expected result
    cout << "Expected result: " << endl
    << "Time in hour: 1.675" << endl
    << "Time in minute: 100.5" << endl
    << "Time in second: 6030" << endl;
    
    // output the result of copy, Time object
    cout << "Actual result: " << endl
    << "Time in hour: " << timeHours << endl
    << "Time in minute: " << timeMinutes << endl
    << "Time in second: " << timeSeconds << endl;
    
    // assertion for result
    assert((timeHours <= 1.676) && (timeHours >= 1.674));
    assert( 100.5 == timeMinutes );
    assert( 6030 == timeSeconds );
  }
  
  // object assignment testing
  {
    cout << "\nObject assignment testing" << endl;
    Time copy; copy = time; //declare copy of copy object
    
    // calculate the time in hour, minute and second using copy
    timeHours = copy.timeInHours();
    timeMinutes = copy.timeInMinutes();
    timeSeconds = copy.timeInSeconds();
    
    // output expected result
    cout << "Expected result: " << endl
    << "Time in hour: 1.675" << endl
    << "Time in minute: 100.5" << endl
    << "Time in second: 6030" << endl;
    
    // output the result of copy, Time object
    cout << "Actual result: " << endl
    << "Time in hour: " << timeHours << endl
    << "Time in minute: " << timeMinutes << endl
    << "Time in second: " << timeSeconds << endl;
    
    // assertion for result
    assert((timeHours <= 1.676) && (timeHours >= 1.674));
    assert( 100.5 == timeMinutes );
    assert( 6030 == timeSeconds );
  }
}
