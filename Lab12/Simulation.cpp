// Lab 12, Write A Customer Service Simulation
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)

#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <vector>
#include <iomanip>
using namespace std;

struct Customer
{
  int arrTime; // clock time that the customer arrives to be placed in the wait queue
  int serTime; // clock time that the customer's service starts, either by arriving when a server is idle, or by moving out of the wait queue
  int comTime; // clock time that the customer's service ends
  char id; // stored as a single letter of the alphabet, A-Z

};
struct ServiceEvent
{
  int clockTime;
  int serverNum;
  bool operator<(const ServiceEvent& s) const { return  s.clockTime < clockTime;  }
};

int getRandomNumberOfServiceRequests(double averageRequestsPerTimeStep)
{
  int requests = 0;
  double probOfnRequests = exp(-averageRequestsPerTimeStep);
  for (double randomValue = (double)rand() / RAND_MAX;
       (randomValue -= probOfnRequests) > 0.0;
       probOfnRequests *= averageRequestsPerTimeStep / (double)++requests);
  return requests;
}

int main()
{
  srand(time(0)); // seed the random
  rand();
  
  // print my name and this assignment's title
  cout << "Lab 12, Write A Customer Service Simulation \n";
  cout << "Programmer: Kwun Hang Chan\n";
  cout << "Editor(s) used: Xcode\n";
  cout << "Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  // read the input values from a text file, one per line, in the order specified above.
  ifstream fin;
  fin.open("simulation.txt"); // open a file
  
  if (!fin.good())
  {
    cout << "geo.txt cannot be found. \n";
    return 1; // exit if file not found
  }
  
  int numOfServers;
  double averageArrRate;
  int maxQueue;
  int minSerTime;
  int maxSerTime;
  int timeStop;

  string buf;
  fin >> buf;
  numOfServers = atoi(buf.c_str());
  fin >> buf;
  averageArrRate = atof(buf.c_str());
  fin >> buf;
  maxQueue = atoi(buf.c_str());
  fin >> buf;
  minSerTime = atoi(buf.c_str());
  fin >> buf;
  maxSerTime = atoi(buf.c_str());
  fin >> buf;
  timeStop = atoi(buf.c_str());
  
  fin.close();
  
  double expTurnAwayRate = averageArrRate - (numOfServers / ((double)(maxSerTime - minSerTime) / 2));
  
  // output the the input information
  cout << "number of server:      " << numOfServers<< endl;
  cout << "customer arrival rate: " << averageArrRate << " per minute, for " << timeStop << " minutes" << endl;
  cout << "maximum queue length:  " << maxQueue << endl;
  cout << "minimum service time:  " << minSerTime << " minutes" << endl;
  cout << "maximum service time:  " << maxSerTime << " minutes" << endl;
  cout << "expected turn away rate : " << setprecision(3)
  << expTurnAwayRate << " per minute, while full" << endl << endl;
  
  // declare and create and assign arrays and queues to be used in the solution
  queue<Customer> customerQ;
  priority_queue<ServiceEvent> servicesPQ;
  vector<Customer> complete;
  vector<Customer> serverArray(numOfServers);
  vector<bool> busyArray(numOfServers);
  
  int numOfCustomer = 0; // # of customer
  int turnAwayNum = 0;
  
  
  // the clock time loop
  for (int time = 0;; time++) // the clock time
  {
    // handle all service events scheduled to complete at this clock time
    while ( !servicesPQ.empty() &&  servicesPQ.top().clockTime == time)
    {
      ServiceEvent se = servicesPQ.top(); servicesPQ.pop();
      serverArray[se.serverNum].comTime = time;
      complete.push_back( serverArray[se.serverNum] );
      busyArray[se.serverNum] = false;
    }
    
    // handle new arrivals -- can be turned away if wait queue is at maximum length!
    if (time < timeStop)
    {
      //get the #of of arrivals from the Poisson process (a whole number >= 0)
      int numOfArrival = getRandomNumberOfServiceRequests(averageArrRate);
      for ( int i = 0 ; i < numOfArrival ; i++ )
      {
        if (customerQ.size() == maxQueue)
        {
          turnAwayNum++;
          numOfCustomer++;
        }
        else
        {
          Customer c;
          c.arrTime = time;
          c.id = (char)('A' + (numOfCustomer++ % 26));
          customerQ.push(c);
        }
      }
    }

    // for idle servers, move customer from wait queue and begin service
    for ( int s = 0 ; s < numOfServers ; s++ )
    {
      if ( busyArray[s] == false && !customerQ.empty() )
      {
        serverArray[s] = customerQ.front(); customerQ.pop();
        serverArray[s].serTime = time;
        serverArray[s].comTime = time + ( rand() %( maxSerTime - minSerTime +1) + minSerTime );
        busyArray[s] = true;

        ServiceEvent newSE;
        newSE.clockTime = serverArray[s].comTime;
        newSE.serverNum = s;
        servicesPQ.push(newSE);
      }
    }
    
    // output the summary
    cout << "Time: " << time << endl;
    cout << "---------------------------" << endl;
    cout << "line now serving wait queue" << endl;
    cout << "---- ----------- ----------" << endl;
    for ( int s = 0 ; s < numOfServers ; s++ )
    {
      cout << "  " << s << " " ;
      if ( busyArray[s] == true ) cout << "      " << serverArray[s].id << "     ";
      if ( s == 0 && !customerQ.empty() )
      {
        cout << " ";
        for( queue<Customer> copy = customerQ; !copy.empty() ; copy.pop() )
          cout << copy.front().id;
      }
      cout << endl;
    }
    cout << "---------------------------" << endl;
  
    // summarize performance
    if ( time > 0 )
    {
      cout.setf(ios::fixed|ios::showpoint);
      double total = 0.0;
      for( int i = 0; i < complete.size() ; i++ )
        total += complete[i].comTime-complete[i].arrTime;
      double avgTime = 0.0;
      if( complete.size() > 0 )
      {
        avgTime = total / complete.size();
        cout << "Avg time: " << setprecision(3) << avgTime << " ";
      }
      cout << "Turned away per minute: " << setprecision(3)
      << (double) turnAwayNum / time <<endl;
    }

    // if the user wants to quit, break out of this loop
    cout << "Press ENTER to continue, X-ENTER to exit..." << endl;
    char exit;
    cin.get(exit);
    if( exit == 'x' || exit == 'X') break;
  }
}