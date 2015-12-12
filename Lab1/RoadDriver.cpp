// Lab 1a, Class Programming and Testing
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)
#include <iostream>
using namespace std;

#include <cassert>

#include "Road.h"
#include "Road.h" // testing ifndef

int main()
{
  // print my name and this assignment's title
  cout << "Lab 1a, Class Programming and Testing\n";
  cout << "Programmer: Kwun Hang Chan\n";
  cout << "Editor(s) used: Xcode\n";
  cout << "Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  // test getters and setters
  Road road;
  int length = 10;
  int width = 5;
  
  cout << "Set width to 5" << endl;
  road.setWidth(5);
  cout << "Expected width = 5   Actual width = " << road.getWidth() << endl;
  assert(5 == road.getWidth());
  
  cout << "Set length to 10" << endl;
  road.setLength(10);
  cout << "Expected length = 10   Actual width = " << road.getLength() << endl;
  assert(10 == road.getLength());
  
  cout << "Create thickness with value 6" << endl;
  int thickness = 6;
  cout << "Expected volume of asphalt is 131999 (=(6*0.0833333) * (10*5280) * 5)\n"
  << "Actual volume = " << road.asphalt(thickness) << "\n\n";
  assert(131999 == road.asphalt(thickness));
  
  // object copy testing
  {
    const Road copy = road; // create object
    cout << "\nCopied Object named as copy." << endl;
    
    // testing copy value and assert if fail
    cout << "Expected width = 5   Actual width = " << copy.getWidth() << endl;
    assert(5 == copy.getWidth());
    cout << "Expected length = 10   Actual width = " << copy.getLength() << endl;
    assert(10 == copy.getLength());
    cout << "Expected volume of asphalt is 131999 (=(6*0.0833333) * (10*5280) * 5)\n"
    << "Actual volume = " << copy.asphalt(thickness) << "\n\n";
    assert(131999 == copy.asphalt(thickness));
  }
  
  // object assignment testing
  {
    cout << "\nObject assignment testing" << endl;
    Road copy; copy = road;
    
    // testing copy value and assert if fail
    cout << "Expected width = 5   Actual width = " << copy.getWidth() << endl;
    assert(5 == copy.getWidth());
    cout << "Expected length = 10   Actual width = " << copy.getLength() << endl;
    assert(10 == copy.getLength());
    cout << "Expected volume of asphalt is 131999 (=(6*0.0833333) * (10*5280) * 5)\n"
    << "Actual volume = " << copy.asphalt(thickness) << "\n\n";
    assert(131999 == copy.asphalt(thickness));
  }
}
