// Lab 6b, Big Data Solutions
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

struct SC
{
  string course;
  int count;
};
struct LS
{
  string subject;
  DynamicArray<SC> courses;
};
struct seen
{
  string term;
  DynamicArray<int> sections;
};
int main()
{
  // print my name and this assignment's title
  cout << "Lab 6b, Big Data Solutions\n";
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
  int i = 0, j = 0, k = 0; // count for looping
  bool seenBefore = false;
  int aSize = 0, cSize = 0, sSize = 0, secSize = 0;
  DynamicArray<LS> a(500); // create a dynamic array for LS
  DynamicArray<string> termSections(70000); // create a dynamic array for term and section
  DynamicArray<seen> seenArray(50); // create a dynamic array for duplicate test
  
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
        if( a[i].subject == subjectCode ) // if match
        {
          cSize = a[i].courses.size();
          for ( k = 0 ; k < cSize ; k++ )
          {
            if ( a[i].courses[k].course == course )
            {
              a[i].courses[k].count++;
              break;
            }
          }
          if ( cSize == k )
          {
            SC newCourse;
            newCourse.course = course;
            newCourse.count = 1;
            a[i].courses[k] = newCourse;
          }
          break;
        }
      }
      if ( aSize == i )
      {
        LS newSubject;
        newSubject.subject = subjectCode;
        SC newCourse;
        newCourse.course = course;
        newCourse.count = 1;
        newSubject.courses[0] = newCourse;
        a[i] = newSubject;
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
      if ( a[j].subject < a[i].subject )
        swap ( a[j], a[i] );
  for ( int i = 0 ; i < aSize ; i++ )
  {
    cSize = a[i].courses.size();
    for ( int x = 0 ; x < cSize ; x++ )
      for (int y = x + 1 ; y < cSize ; y ++ )
        if ( a[i].courses[y].course < a[i].courses[x].course )
          swap ( a[i].courses[y], a[i].courses[x] );
  }
  
  // stop timer
  cout << "Timer stops\n";
  double elapsedSeconds = (double) (clock() - startTime) / CLOCKS_PER_SEC;
  
  // output result
  cout << "Output:" << endl;
  cout << "a size:" <<a.size() << endl;
  for ( int i = 0 ; i < a.size() ; i++ )
  {
    cout << a[i].subject << ", " << a[i].courses.size() << " course(s)" << endl;
    cSize = a[i].courses.size();
    for ( k = 0 ; k < cSize ; k ++ )
      cout << "  " << a[i].courses[k].course << ", "
      <<  a[i].courses[k].count << " section(s)" << endl;
  }
  
  // output excel
  ofstream fout; // requires fstream
  fout.open("dvc-schedule.xls");
  if (!fout.good()) throw "I/O error";
  fout << "Subject \tCourse(s) \tClass\t Section(s) \n";
  for ( int i = 0 ; i < a.size() ; i++ )
  {
    fout << a[i].subject << '\t' << a[i].courses.size() << '\n';
    cSize = a[i].courses.size();
    for ( k = 0 ; k < cSize ; k ++ )
      fout << "\t\t" << a[i].courses[k].course << '\t'
      <<  a[i].courses[k].count << '\n';
  }
  fout.close();
  
  cout << "There are " << n_dup << " duplicate records." << endl;
  cout << "The process took " << elapsedSeconds << " seconds to process and sort the file" << endl;
}