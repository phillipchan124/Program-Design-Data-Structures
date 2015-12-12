// Lab 8c, Perform A Timing Study On The STL Array Sort Function
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)
#include <iostream> // for cout and endl
#include <string> // for string
using namespace std;

#include <cassert> // for assert
#include <cmath> // for log and pow
#include <ctime> // for clock() and clock_t
#include <algorithm> // for swap

int main()
{
  // print my name and this assignment's title
  cout << "Lab 8c, Perform A Timing Study On The STL Array Sort Function\n";
  cout << "Programmer: Kwun Hang Chan\n";
  cout << "Editor(s) used: Xcode\n";
  cout << "Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  // programmer customizations go here
  int n = 2500000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  string bigOh = "O(n log n)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)
  int elapsedTimeTicksNorm = 0;
  double expectedTimeTicks = 0;
  srand (time(0));
  
  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    // more problem setup goes here -- the stuff not timed
    double *a = new double[n];
    for (int i = 0; i < n; i++)
      a[i] = rand();
    
    // start the timer, do something, and stop the timer
    clock_t startTime = clock();
    
    sort(a, a+n);
    
    clock_t endTime = clock();
    
    for (int i = 1; i < n; i++)
      assert(a[i - 1] <= a[i]);
    
    delete [] a;
    
    // compute timing results
    long elapsedTimeTicks = (long)(endTime - startTime);
    double factor = pow(2.0, cycle);
    if (cycle == 0)
      elapsedTimeTicksNorm = elapsedTimeTicks;
    else if (bigOh == "O(1)")
      expectedTimeTicks = elapsedTimeTicksNorm;
    else if (bigOh == "O(log n)")
      expectedTimeTicks = log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n)")
      expectedTimeTicks = factor * elapsedTimeTicksNorm;
    else if (bigOh == "O(n log n)")
      expectedTimeTicks = factor * log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n squared)")
      expectedTimeTicks = factor * factor * elapsedTimeTicksNorm;
    
    // reporting block
    cout << elapsedTimeTicks;;
    if (cycle == 0) cout << " (expected " << bigOh << ')';
    else cout << " (expected " << expectedTimeTicks << ')';
    cout << " for n=" << n << endl;
  }
}