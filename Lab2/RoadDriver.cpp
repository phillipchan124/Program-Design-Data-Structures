// Lab 2b, Writing Templates And Overloading Operators
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
  cout << "Lab 2b, Writing Templates And Overloading Operators\n";
  cout << "Programmer: Kwun Hang Chan\n";
  cout << "Editor(s) used: Xcode\n";
  cout << "Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  // testing -- int
  {
    // test getters and setters
    cout << "Testing int for Road" << endl;
    Road <int> road;

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
      const Road <int> copy = road; // create object
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
      Road <int> copy; copy = road;
    
      // testing copy value and assert if fail
      cout << "Expected width = 5   Actual width = " << copy.getWidth() << endl;
      assert(5 == copy.getWidth());
      cout << "Expected length = 10   Actual width = " << copy.getLength() << endl;
      assert(10 == copy.getLength());
      cout << "Expected volume of asphalt is 131999 (=(6*0.0833333) * (10*5280) * 5)\n"
      << "Actual volume = " << copy.asphalt(thickness) << "\n\n";
      assert(131999 == copy.asphalt(thickness));
    }
  
    // testing overloading operator <
    {
      Road<int> r1, r2;
      // set hour, minute and second for time
      cout << "Testing overloading operator <" << endl;
      r1.setLength(5); r1.setWidth(10);
      r2.setLength(5); r2.setWidth(11);
      cout << "Create two Road object r1, r2" << endl
      << "Set r1 (width = 10, length = 5) and r1 (width = 11, length = 5)" << endl
      << "Expected result for r1<r2 is false"<< endl;
      cout << "Actual result: ";
      ( r1 < r2 )? cout << "true" << endl: cout << "false" << endl;
      assert( false == r1 < r2 );
      cout << "Set r2 as with length = 6" << endl
      << "Expected result for r1<r2 is true"<< endl;
      r2.setLength(6);
      cout << "Actual result: ";
      ( r1 < r2 )? cout << "true" << endl: cout << "false" << endl;
      assert( true == r1 < r2 );
      cout<< "Set r1 with length = 7" << endl
      << "Expected result for r1<r2 is false"<< endl;
      r1.setLength(7);
      cout << "Actual result: ";
      ( r1 < r2 )? cout << "true" << endl: cout << "false" << endl<< endl;
      assert( false == r1 < r2 );
    }
  
    // testing overloading operator ==
    {
      Road<int> r1, r2;
      // set hour, minute and second for time
      cout << "Testing overloading operator ==" << endl;
      r1.setLength(5); r1.setWidth(10);
      r2.setLength(5); r2.setWidth(11);
      cout << "Create two Road object r1, r2" << endl
      << "Set r1 (width = 10, length = 5) and r1 (width = 11, length = 5)" << endl
      << "Expected result for r1==r2 is false"<< endl;
      cout << "Actual result: ";
      ( r1 == r2 )? cout << "true" << endl: cout << "false" << endl;
      assert( false == (r1 == r2) );
      cout << "Set r2 as with width = 10" << endl
      << "Expected result for r1==r2 is true"<< endl;
      r2.setWidth(10);
      cout << "Actual result: ";
      ( r1 == r2 )? cout << "true" << endl: cout << "false" << endl;
      assert( true == (r1 == r2) );
      cout<< "Set r1 with length = 7" << endl
      << "Expected result for r1==r2 is false"<< endl;
      r2.setLength(7);
      cout << "Actual result: ";
      ( r1 == r2 )? cout << "true" << endl: cout << "false" << endl<< endl;
      assert( false == (r1 == r2));
    }
  }
  
  // testing -- double
  {
    // test getters and setters
    cout << "Testing double for Road" << endl;
    Road <double> road;
  
    cout << "Set width to 3.21" << endl;
    road.setWidth(3.21);
    cout << "Expected width = 3.21   Actual width = " << road.getWidth() << endl;
    assert(3.21 == road.getWidth());
  
    cout << "Set length to 8.52" << endl;
    road.setLength(8.52);
    cout << "Expected length = 8.52   Actual width = " << road.getLength() << endl;
    assert(8.52 == road.getLength());
  
    cout << "Create thickness with value 1.23" << endl;
    double thickness = 1.23;
    cout << "Expected volume of asphalt is 14801.38 (=(1.23*0.0833333) * (8.52*5280) * 3.21)\n"
    << "Actual volume = " << road.asphalt(thickness) << "\n\n";
    assert(14801.37 < road.asphalt(thickness) &&  road.asphalt(thickness) < 14801.39);
    
    // object copy testing
    {
      const Road <double> copy = road; // create object
      cout << "\nCopied Object named as copy." << endl;
      
      // testing copy value and assert if fail
      cout << "Expected width = 3.21   Actual width = " << copy.getWidth() << endl;
      assert(3.21 == copy.getWidth());
      cout << "Expected length = 10   Actual width = " << copy.getLength() << endl;
      assert(8.52 == copy.getLength());
      cout << "Expected volume of asphalt is 14801.38 (=(1.23*0.0833333) * (8.52*5280) * 3.21)\n"
      << "Actual volume = " << copy.asphalt(thickness) << "\n\n";
      assert(14801.37 < copy.asphalt(thickness) &&  copy.asphalt(thickness) < 14801.39);
    }
    
    // object assignment testing
    {
      cout << "\nObject assignment testing" << endl;
      Road <double> copy; copy = road;
      
      // testing copy value and assert if fail
      cout << "Expected width = 3.21   Actual width = " << copy.getWidth() << endl;
      assert(3.21 == copy.getWidth());
      cout << "Expected length = 10   Actual width = " << copy.getLength() << endl;
      assert(8.52 == copy.getLength());
      cout << "Expected volume of asphalt is 14801.38 (=(1.23*0.0833333) * (8.52*5280) * 3.21)\n"
      << "Actual volume = " << copy.asphalt(thickness) << "\n\n";
      assert(14801.37 < copy.asphalt(thickness) &&  copy.asphalt(thickness) < 14801.39);
    }
    
    // testing overloading operator <
    {
      Road<double> r1, r2;
      // set hour, minute and second for time
      cout << "Testing overloading operator <" << endl;
      r1.setLength(5.12); r1.setWidth(10.34);
      r2.setLength(5.12); r2.setWidth(10.34);
      cout << "Create two Road object r1, r2" << endl
      << "Set r1 (width = 10.34, length = 5.12) and r2 (width = 10.34, length = 5.12)" << endl
      << "Expected result for r1<r2 is false"<< endl;
      cout << "Actual result: ";
      ( r1 < r2 )? cout << "true" << endl: cout << "false" << endl;
      assert( false == r1 < r2 );
      cout << "Set r2 as with length = 6.5" << endl
      << "Expected result for r1<r2 is true"<< endl;
      r2.setLength(6.5);
      cout << "Actual result: ";
      ( r1 < r2 )? cout << "true" << endl: cout << "false" << endl;
      assert( true == r1 < r2 );
      cout<< "Set r1 with length = 8.5" << endl
      << "Expected result for r1<r2 is false"<< endl;
      r1.setLength(8.5);
      cout << "Actual result: ";
      ( r1 < r2 )? cout << "true" << endl: cout << "false" << endl<< endl;
      assert( false == r1 < r2 );
    }
    
    // testing overloading operator ==
    {
      Road<double> r1, r2;
      // set hour, minute and second for time
      cout << "Testing overloading operator ==" << endl;
      r1.setLength(5.12); r1.setWidth(10.34);
      r2.setLength(5.12); r2.setWidth(9.83);
      cout << "Create two Road object r1, r2" << endl
      << "Set r1 (width = 10.34, length = 5.12) and r2 (width = 9.83, length = 5.12)" << endl
      << "Expected result for r1==r2 is false"<< endl;
      cout << "Actual result: ";
      ( r1 == r2 )? cout << "true" << endl: cout << "false" << endl;
      assert( false == (r1 == r2) );
      cout << "Set r2 as with width = 10.35" << endl
      << "Expected result for r1==r2 is true"<< endl;
      r2.setWidth(10.34);
      cout << "Actual result: ";
      ( r1 == r2 )? cout << "true" << endl: cout << "false" << endl;
      assert( true == (r1 == r2) );
      cout<< "Set r1 with length = 6.23" << endl
      << "Expected result for r1==r2 is false"<< endl;
      r2.setLength(6.23);
      cout << "Actual result: ";
      ( r1 == r2 )? cout << "true" << endl: cout << "false" << endl<< endl;
      assert( false == (r1 == r2));
    }
  }
}
