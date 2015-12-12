// Lab 5a, Applying A Data Structure To A Big Data Application
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include <algorithm>
#include <ctime>

#include "DynamicArray.h"

struct Subject
{
  string subjectCode;
  int count;
};

int main()
{
  // print my name and this assignment's title
  cout << "Lab 5a, Applying A Data Structure To A Big Data Application \n";
  cout << "Programmer: Kwun Hang Chan\n";
  cout << "Editor(s) used: Xcode\n";
  cout << "Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  // for parsing the inputfile
  char* token;
  char buf[1000];
  const char* const tab = "\t";
  int n = 0; // count for record
  int n_dup = 0; // count for duplicates
  int i = 0, j = 0; // count for looping
  bool seenBefore = false;
  string termSection;
  int termSectionsSize = 0;
  int aSize = 0;
  DynamicArray<Subject> a(500); // create a dynamic array for subject
  DynamicArray<string> termSections(70000); // create a dynamic array for term and section
  
  // start timer
  cout << "Timer starts.\n";
  clock_t startTime = clock();
  
  // open the input file
  ifstream fin;
  cout << "Open input file.\n";
  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";
  
  // read the input file
  cout << "Process input file.\n";
  while (fin.good())
  {
    // read the line
    string line;
    getline(fin, line);
    strcpy(buf, line.c_str());
    if (buf[0] == 0) continue;
    if ( ++n % 1000 == 0 ) { cout << '.'; cout.flush(); }
    
    // parse the line
    const string term(token = strtok(buf, tab));
    const string section(token = strtok(0, tab));
    const string course((token = strtok(0, tab)) ? token : "");
    const string instructor((token = strtok(0, tab)) ? token : "");
    const string whenWhere((token = strtok(0, tab)) ? token : "");
    if (course.find('-') == string::npos) continue; // invalid line
    const string subjectCode(course.begin(), course.begin() + course.find('-'));

    // check duplicate
    seenBefore = false;
    termSection = term + section;
    termSectionsSize = termSections.size();
    
    for ( j = 0 ; j < termSectionsSize ; j ++ )
    {
      if ( termSection == termSections[j] )
      {
        seenBefore = true;
        n_dup++;
        continue;
      }
    }
    
    if (!seenBefore)
    {
      termSections[j] = termSection;
      // search dynamic array, a
      aSize = a.size();
      for ( i = 0 ; i < aSize ; i++ )
      {
        if( a[i].subjectCode == subjectCode ) // if match
        {
          a[i].count++;
          break;
        }
      }
      if ( aSize == i )
      {
        Subject subject;
        subject.subjectCode = subjectCode;
        subject.count = 1;
        a[i] = subject;
      }
    }
  }
  
  // close input file
  cout << "\nClose input file.";
  fin.close();
  
  // sort
  cout << "\nSorting." << endl;
  aSize = a.size();
  for ( int i = 0 ; i < aSize ; i++ )
    for (int j = i + 1 ; j < aSize ; j ++ )
      if ( a[j].subjectCode < a[i].subjectCode )
        swap ( a[j], a[i]);
  
  // stop timer
  cout << "Timer stops\n";
  double elapsedSeconds = (double) (clock() - startTime) / CLOCKS_PER_SEC;
  
  // output result
  cout << "Output:" << endl;
  aSize = a.size();
  for ( int i = 0 ; i < aSize ; i++ )
  {
    cout << a[i].subjectCode << ", " << a[i].count << " sections" << endl;
  }
  cout << "There are " << n_dup << " duplicate records." << endl;
  cout << "The process took " << elapsedSeconds << " seconds to process and sort the file" << endl;
}