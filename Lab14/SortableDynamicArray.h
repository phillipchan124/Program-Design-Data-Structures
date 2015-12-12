// Lab 14a, Write A Sortable Array Class Template
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)
#ifndef SortableDynamicArray_h
#define SortableDynamicArray_h

#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

template<class T>
class SortableDynamicArray
{
  static const int INIT_CAP = 100; // initial capacity
  int cap;
  T* values;
  bool* inUse;
  T dummy;
public:
  SortableDynamicArray( int=INIT_CAP ); // default constructor
  ~SortableDynamicArray(); // destructor
  SortableDynamicArray( const SortableDynamicArray<T>& ); // copy constructor
  SortableDynamicArray<T>& operator=( const SortableDynamicArray<T>& ); // assignment operator
  T& operator[](int); // lookup key is an index
  T operator[](int) const;
  int size() const; // #of keys "in use", initially zero
  int capacity() const;
  bool containsKey(int) const;
  void deleteKey(int); // set "in use" to false
  vector<int> keys() const; // all "in use" keys
  void clear();
  void sort(int);
  int bsearch(int, const T&) const;
};
template <class T>
SortableDynamicArray<T>::SortableDynamicArray( int init_cap )
{
  cap = init_cap;
  values = new T[cap];
  inUse = new bool[cap];
  for ( int i = 0; i < cap ; i++)
    inUse[i] = false;
}
template <class T>
SortableDynamicArray<T>::~SortableDynamicArray()
{
  delete [] values;
  delete [] inUse;
}
template <class T>
SortableDynamicArray<T>::SortableDynamicArray( const SortableDynamicArray<T>& a)
{
  cap = a.cap;
  values = new T[cap];
  inUse = new bool[cap];
  
  for ( int i = 0 ; i < cap ; i ++)
  {
    values[i] = a.values[i];
    inUse[i] = a.inUse[i];
  }
}
template <class T>
SortableDynamicArray<T>& SortableDynamicArray<T>::operator=( const SortableDynamicArray<T>& a)
{
  if ( this == &a ) return *this;
  
  delete [] values;
  delete [] inUse;
  
  cap = a.cap;
  values = new T[cap];
  inUse = new bool[cap];
  
  for ( int i = 0 ; i < cap ; i ++)
  {
    values[i] = a.values[i];
    inUse[i] = a.inUse[i];
  }
  
  return *this;
}
template <class T>
T& SortableDynamicArray<T>::operator[](int key) // lookup key is an index
{
  if (key < 0 ) return dummy;
  if (key>=cap)
  {
    T* tempValues = new T[key+1];
    for (int i =0; i < cap; i++ ) tempValues[i] = values[i];
    delete [] values;
    values = tempValues;
    
    bool* tempInUse = new bool[key+1];
    for (int i = 0; i < cap; i++ ) tempInUse[i] = inUse[i];
    for (int i = cap; i <= key; i++ ) tempInUse[i] = false;
    delete [] inUse;
    inUse = tempInUse;
    
    cap = key + 1;
  }
  inUse[key] = true;
  return values[key];
}
template <class T>
T SortableDynamicArray<T>::operator[](int key) const
{
  if (key < 0 || key >= cap) return dummy;
  if (inUse[key] == false) return dummy;
  return values[key];
}
template <class T>
int SortableDynamicArray<T>::size() const // #of keys "in use", initially zero
{
  int count = 0;
  for ( int i = 0; i < cap ; i++)
    if ( containsKey(i) )
      count++;
  return count;
}
template <class T>
int SortableDynamicArray<T>::capacity() const
{
  return cap;
}
template <class T>
bool SortableDynamicArray<T>::containsKey(int index) const
{
  if (index < 0) return false;
  if (index >= cap) return false;
  return inUse[index];
}
template <class T>
void SortableDynamicArray<T>::deleteKey(int index) // set "in use" to false
{
  if (index < 0) return;
  if (index >= cap) return;
  inUse[index] = false;
}
template <class T>
vector<int> SortableDynamicArray<T>::keys() const // all "in use" keys
{
  vector<int> v;
  for ( int i = 0; i < cap ; i++)
    if ( containsKey(i) )
      v.push_back(values[i]);
  return v;
}
template <class T>
void SortableDynamicArray<T>::clear()
{
  for ( int i = 0; i < cap ; i++)
    inUse[i] = false;
}

template <class T>
void SortableDynamicArray<T>::sort(int num)
{
  for ( int i = 0; i < num ; i++)
    if (!inUse[i]) return;
    
  stack<pair<int, int> > todo;
  todo.push(pair<int, int>(0, num));
  while (!todo.empty())
  {
    int start = todo.top().first;
    int end = todo.top().second;
    todo.pop();
    if (start >= end) continue;
    
    int pivot = (start + end - 1) / 2;
    int left = start;
    int right = end - 1;
    while (true)
    {
      while (left < pivot && values[left] <= values[pivot]) left++;
      while (pivot < right && values[pivot] <= values[right]) right--;
      if (left == right)
      {
        todo.push(pair<int, int>(start, pivot));
        todo.push(pair<int, int>(pivot + 1, end));
        break;
      }
      else if (left == pivot)
      {
        swap(values[pivot], values[right]);
        pivot = right;
        left++;
      }
      else if (pivot == right)
      {
        swap(values[left], values[pivot]);
        pivot = left;
        right--;
      }
      else
      {
        swap(values[left], values[right]);
        left++;
        right--;
}  } } }
template <class T>
int SortableDynamicArray<T>::bsearch(int num, const T& param) const
{
  int result = -1;
  for ( int i = 0; i < num ; i++)
    if (!inUse[i]) return result;
  
  int s = 0;
  int e = num;
  
  while(true)
  {
    int m = (s + e - 1) / 2;
    if (param == values[m])
      return m;
    else if (s == e - 1)
      return -1;
    else if (param < values[m])
    {
      if (s == m) return -1;
      else { e = m ; continue; }
    }
    else
    {
      if (m == e - 1) return -1;
      else { s = m + 1; continue; }
    }
  }
}

#endif