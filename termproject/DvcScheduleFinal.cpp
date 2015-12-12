// Term Project
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include <ctime>
#include <map>
#include <set>

int main()
{
  // print my name and this assignment's title
  cout << "Term Project\n";
  cout << "Programmer: Kwun Hang Chan\n";
  cout << "Editor(s) used: Xcode\n";
  cout << "Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  // for parsing the inputfile
  char* token;
  char buf[1000];
  const char* const tab = "\t";
  int n = 0, n_dup = 0; // count for duplicates
  string termSection;
  map<string, int> sc;
  map<string, int>::iterator itsc;
  map<string, map<string, int> > m;
  map<string, map<string, int> >::iterator it;
  set<string> dup;
  set<string>::iterator itd;
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
    termSection = term + section;
    itd = dup.find(termSection);
    if( itd !=dup.end() )
    {
      n_dup++;
      continue;
    }
    else
    {
      dup.insert(termSection); // insert into dulplicate map
      it = m.find(subjectCode);
      if( it == m.end() ) m[subjectCode][course] = 1; // if not found, add to m
      else
      {
        itsc = m[subjectCode].find(course);
        // if course not found, add the course with count 1
        if( itsc == sc.end()) m[subjectCode].insert( pair<string,int>(course,1) );
        // else, add the count
        else m[subjectCode][course]++;
      }
    }
  }
  // close input file
  cout << "\nClose input file.";
  fin.close();
  // stop timer
  cout << "Timer stops\n";
  double elapsedSeconds = (double) (clock() - startTime) / CLOCKS_PER_SEC;
  // output result
  for (it = m.begin(); it!=m.end(); it++)
  {
    cout << it->first << ", " << it->second.size() << " course(s)" << endl ;
    for (itsc = it->second.begin(); itsc!= it->second.end(); itsc++)
      cout << " " << itsc->first << ", " << itsc->second << " section(s)" << endl;
  }
  cout << "There are " << n_dup << " duplicate records." << endl;
  cout << "The process took " << elapsedSeconds << " seconds to process and sort the file" << endl;
}