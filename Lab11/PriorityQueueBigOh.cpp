// Lab 11b, Perform A Timing Study
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)

#include <iostream> // for cout and endl
#include <string> // for string
using namespace std;

#include <cmath> // for log and pow
#include <ctime> // for clock() and clock_t
#include <algorithm> // for swap
#include <cassert> // for assert

#include "PriorityQueue.h"

int main()
{
  // print my name and this assignment's title
  cout << "Lab 11b, Perform A Timing Study \n";
  cout << "Programmer: Kwun Hang Chan\n";
  cout << "Editor(s) used: Xcode\n";
  cout << "Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  // programmer customizations go here
  int n = 10000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  string bigOh = "O(log n)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)
  
  int elapsedTimeTicksNorm = 0;
  double expectedTimeTicks = 0;
  
  const int REPS = 100; // for timing fast operations, use REPS up to 100th of the starting n
  
  cout << "enqueue, O(log n)" << endl;
  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    // more problem setup goes here -- the stuff not timed
    PriorityQueue<int> pq(81000);
    
    //for (int i = n; i > 0; i--)
    for(int i = 0; i < n; i++)
    {
      pq.enqueue(n - i);
    }

    // start the timer, do something, and stop the timer
    clock_t startTime = clock();
    
    for (int j = 1; j <= REPS; j++)
    {
        pq.enqueue((n+j));
    }
    
    clock_t endTime = clock();
    
    // testing the order
    int test[REPS];
    for (int i = 0; i < REPS; i++) test[i] = pq.dequeue();
    for (int i = 1; i < REPS-1 ; i++)
    {
      assert(test[i+1] <= test[i]);
    }
    
    int tests[n];
    for (int j = 0; j < n; j++) tests[j] = pq.dequeue();
    for (int j = 1; j < n-1 ; j++)
    {
      assert(tests[j+1] <= tests[j]);
    }
    
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
  
  n = 10000;
  
  elapsedTimeTicksNorm = 0;
  expectedTimeTicks = 0;

  cout << endl << "dequeue, O(log n)" << endl;
  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    // more problem setup goes here -- the stuff not timed
    PriorityQueue<int> pq(81000);
    
    //for (int i = n; i > 0; i--)
    for(int i = 0; i < n; i++)
    {
      pq.enqueue(n - i);
    }
    
    // start the timer, do something, and stop the timer
    clock_t startTime = clock();
    
    for (int j = 1; j <= REPS; j++)
    {
      pq.dequeue();
    }
    
    clock_t endTime = clock();
    
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
