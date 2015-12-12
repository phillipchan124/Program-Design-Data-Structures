// Lab 14b, Applying A Data Structure To A Database Program
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
#include "LinkedArray.h"
#include "SortableDynamicArray.h"

struct Subject
{
  string subjectCode;
  int count;
  bool operator <(const Subject& s) const { return subjectCode < s.subjectCode; }
  bool operator <=(const Subject& s) const { return subjectCode <= s.subjectCode; }
};
struct seen
{
  string term;
  DynamicArray<int> sections;
};

int main()
{
  // print my name and this assignment's title
  cout << "Lab 14b, Applying A Data Structure To A Database Program\n";
  cout << "Programmer: Kwun Hang Chan\n";
  cout << "Editor(s) used: Xcode\n";
  cout << "Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  // for parsing the input file
  char* token;
  char buf[1000];
  const char* const tab = "\t";
  int n = 0; // count for record
  int n_dup = 0; // count for duplicates
  int i = 0, k = 0; // count for looping
  bool seenBefore = false;
  int aSize = 0, sSize = 0, secSize = 0; //, kSize = 0;
  SortableDynamicArray<Subject> a(500); // create a sortable static array for subject
  LinkedArray<seen> seenArray(50); // create a linked array for term and section
  
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
    sSize = seenArray.size();
    for ( i = 0 ; i < sSize ; i++ )
    {
      if( seenArray[i].term == term ) // if match
      {
        secSize = seenArray[i].sections.size();
        for ( k = 0 ; k < secSize ; k++ )
        {
          if ( seenArray[i].sections[k] == stoi(section) )
          {
            seenBefore = true;
            n_dup++;
            break;
          }
        }
        if ( secSize == k )
        {
          seenArray[i].sections[k] = stoi(section);
        }
        break;
      }
    }
    if ( sSize == i )
    {
      seen termSection;
      termSection.term = term;
      termSection.sections[0] = stoi(section);
      seenArray[i] = termSection;
    }
    
    if (!seenBefore)
    {
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
  a.sort(a.size());
  
  // stop timer
  cout << "Timer stops\n";
  double elapsedSeconds = (double) (clock() - startTime) / CLOCKS_PER_SEC;
  
  // output result
  cout << "Output:" << endl;
  aSize = a.size();
  for ( i = 0 ; i < aSize ; i++ )
  {
    cout << a[i].subjectCode << ", " << a[i].count << " sections" << endl;
  }
  
  cout << "There are " << n_dup << " duplicate records." << endl;
  cout << "The process took " << elapsedSeconds << " seconds to process and sort the file" << endl;
}
