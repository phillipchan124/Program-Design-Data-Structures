// Lab 4a, Write A Dynamic Array Class Template
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)
#ifndef DynamicArray_h
#define DynamicArray_h

#include<vector>
using namespace std;

template<class T>
class DynamicArray
{
  static const int INIT_CAP = 100; // initial capacity
  int cap;
  T* values;
  bool* inUse;
  T dummy;
public:
  DynamicArray( int=INIT_CAP ); // default constructor
  ~DynamicArray(); // destructor
  DynamicArray( const DynamicArray<T>& ); // copy constructor
  DynamicArray<T>& operator=( const DynamicArray<T>& ); // assignment operator
  T& operator[](int); // lookup key is an index
  T operator[](int) const;
  int size() const; // #of keys "in use", initially zero
  int capacity() const;
  bool containsKey(int) const;
  void deleteKey(int); // set "in use" to false
  vector<int> keys() const; // all "in use" keys
  void clear();
};
template <class T>
DynamicArray<T>::DynamicArray( int init_cap )
{
  cap = init_cap;
  values = new T[cap];
  inUse = new bool[cap];
  for ( int i = 0; i < cap ; i++)
    inUse[i] = false;
}
template <class T>
DynamicArray<T>::~DynamicArray()
{
  delete [] values;
  delete [] inUse;
}
template <class T>
DynamicArray<T>::DynamicArray( const DynamicArray<T>& a)
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
DynamicArray<T>& DynamicArray<T>::operator=( const DynamicArray<T>& a)
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
T& DynamicArray<T>::operator[](int key) // lookup key is an index
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
T DynamicArray<T>::operator[](int key) const
{
  if (key < 0 || key >= cap) return dummy;
  if (inUse[key] == false) return dummy;
  return values[key];
}
template <class T>
int DynamicArray<T>::size() const // #of keys "in use", initially zero
{
  int count = 0;
  for ( int i = 0; i < cap ; i++)
    if ( containsKey(i) )
      count++;
  return count;
}
template <class T>
int DynamicArray<T>::capacity() const
{
  return cap;
}
template <class T>
bool DynamicArray<T>::containsKey(int index) const
{
  if (index < 0) return false;
  if (index >= cap) return false;
  return inUse[index];
}
template <class T>
void DynamicArray<T>::deleteKey(int index) // set "in use" to false
{
  if (index < 0) return;
  if (index >= cap) return;
  inUse[index] = false;
}
template <class T>
vector<int> DynamicArray<T>::keys() const // all "in use" keys
{
  vector<int> v;
  for ( int i = 0; i < cap ; i++)
    if ( containsKey(i) )
      v.push_back(values[i]);
  return v;
}
template <class T>
void DynamicArray<T>::clear()
{
  for ( int i = 0; i < cap ; i++)
    inUse[i] = false;
}

#endif