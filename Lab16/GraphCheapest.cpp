// Lab 16b, Write A Function For Cheapest Route
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)
#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <utility>
using namespace std;

#include <cstdlib>

struct Vertex
{
  string name;

  bool isVisited;
  list<pair<int, double> > adjacentVertices;
  int prev;
  double cost;
};
struct Container // vertex container, for multiple ways to get to a vertex
{
  int vertex; // index in database array
  int prev; // index in database array
  double cost;
  
  bool operator<(const Container& v) const { return cost > v.cost;  }
};

pair<stack<int>, double> getCheapestRoute(int iStart, int iEnd, vector<Vertex>& database)
{
  pair<stack<int>, double> result;
  list<pair<int, double> >::iterator it; // to iterate over adjacentVertices

  for (int i = 0; i < database.size() ; i++ )
  {
    database[i].isVisited = false;
    database[i].prev = -1;
    database[i].cost = 0;
  }
  
  priority_queue<Container> pq;
  
  Container cStart;
  cStart.cost = 0;
  cStart.prev = -1;
  cStart.vertex = iStart;
  
  pq.push(cStart);
  
  while (!pq.empty())
  {
    Container c = pq.top(); pq.pop();
    
    if(database[c.vertex].isVisited) continue;
    
    database[c.vertex].isVisited = true;
    database[c.vertex].cost = c.cost;
    database[c.vertex].prev = c.prev;
    
    if( c.vertex == iEnd ) break;
    
    for ( it = database[c.vertex].adjacentVertices.begin();
         it != database[c.vertex].adjacentVertices.end();
         it++)
    {
      Container n;
      n.vertex = it->first;
      n.cost = c.cost + it->second;
      n.prev = c.vertex;
      pq.push(n);
    }
  }

  result.second = database[iEnd].cost;
  
  for (int k = iEnd ; k > -1 ; k = database[k].prev )
    result.first.push(k);
  return result;
}

int main()
{
  // print my name and this assignment's title
  cout << "Lab 16b, Write A Function For Cheapest Route\n";
  cout << "Programmer: Kwun Hang Chan\n";
  cout << "Editor(s) used: Xcode\n";
  cout << "Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  ifstream fin;
  bool foundFrom;
  bool foundTo;
  fin.open("cities.txt");
  if (!fin.good()) throw "I/O error";  

  // process the input file
  vector<Vertex> database;
  while (fin.good()) // EOF loop
  {
    string fromCity, toCity, cost;

    // read one edge
    getline(fin, fromCity);
    getline(fin, toCity);
    getline(fin, cost);
    fin.ignore(1000, 10); // skip the separator
    // TO DO -- code to eliminate whitespace
    fromCity.erase(remove_if(fromCity.begin(), fromCity.end(), ::isspace), fromCity.end());
    toCity.erase(remove_if(toCity.begin(), toCity.end(), ::isspace), toCity.end());

    // add vertices for new cities included in the edge
    int iToVertex = -1, iFromVertex = -1, i;
    for (i = 0; i < database.size(); i++) // seek "to" city
      if (database[i].name == fromCity)
        break;
    if (i == database.size()) // not in database yet
    {
      // store the vertex if it is new
      Vertex fromVertex;
      fromVertex.name = fromCity;
      database.push_back(fromVertex);
    }
    iFromVertex = i; 

    for (i = 0; i < database.size(); i++) // seek "from" city
      if (database[i].name == toCity)
        break;
    if (i == database.size()) // not in vector yet
    {
      // store the vertex if it is new
      Vertex toVertex;
      toVertex.name = toCity;
      database.push_back(toVertex);
    }
    iToVertex = i; 

    // store bi-directional edges
    double edgeCost = atof(cost.c_str());
    database[iFromVertex].adjacentVertices.push_back(pair<int, double>(iToVertex, edgeCost));
    database[iToVertex].adjacentVertices.push_back(pair<int, double>(iFromVertex, edgeCost));
  }
  fin.close();
  cout << "Input file processed\n\n";

  while (true)
  {
    string fromCity, toCity;
    cout << "\nEnter the source city [blank to exit]: ";
    getline(cin, fromCity);
    if (fromCity.length() == 0) break;

    // find the from city
    int iFrom;
    foundFrom = false;
    for (iFrom = 0; iFrom < database.size(); iFrom++)
      if (database[iFrom].name == fromCity)
      {
        foundFrom = true;
        break;
      }
    
    cout << "Enter the destination city [blank to exit]: ";
    getline(cin, toCity);
    if (toCity.length() == 0) break;
    
    // find the destination city
    int iTo;
    foundTo = false;
    for (iTo = 0; iTo < database.size(); iTo++)
      if (database[iTo].name == toCity)
      {
        foundTo = true;
        break;
      }

    // TO DO -- skip the next code block if no matching cites are found
    if ( foundFrom && foundTo )
    {
      pair<stack<int>, double> result = getCheapestRoute(iFrom, iTo, database);
      cout << "Total miles: " << result.second;
      while (!result.first.empty()){cout << '-' << database[result.first.top()].name; result.first.pop();}
      cout << endl;
    }
    else
    {
      if(!foundFrom) cout << "No matching source city." << endl;
      if(!foundTo) cout << "No matching destination city" << endl;
    }
  }
}
