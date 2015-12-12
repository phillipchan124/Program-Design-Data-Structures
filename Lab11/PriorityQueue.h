// Lab 11, Write, Test A Priority Queue Template
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)
#ifndef PriorityQueue_h
#define PriorityQueue_h

#include <algorithm> // for swap

template<class T>
class PriorityQueue
{
private:
  T* values;
  int capacity;
  T dummy;
  mutable int sizes;
  mutable int index;
public:
  PriorityQueue( int=2 ); // default constructor
  void enqueue(const T&);
  T dequeue();
  T& front();
  T& back();
  bool empty() const { return 0 == sizes; }
  void clear() { sizes = 0; }
  int size() const { return sizes; }
};
template<class T>
PriorityQueue<T>::PriorityQueue( int n )
{
  capacity = n;
  values = new T[capacity];
  sizes = 0;
}
template<class T>
void PriorityQueue<T>::enqueue(const T& param)
{
  index = sizes;
  if ( index >= capacity )
  {
    capacity = capacity*2;
    T* temp = new T[capacity];
    for ( int i = 0; i < capacity ; i++ ) temp[i] = values[i];
    delete [] values;
    values = temp;
  }
  values[index] = param;
  while ( index>0 )
  {
    int parentIndex = ((index+1)/2) - 1;
    if ( parentIndex < 0 ) break;
    if ( values[parentIndex] >= values[index] ) break;
    swap ( values[parentIndex], values[index] );
    index = parentIndex;
  }
  ++sizes;
}
template<class T>
T PriorityQueue<T>::dequeue()
{
  T param = values[0];
  index = 0;
  while ( index <= sizes )
  {
    int indexLeft = 2*index +1;
    int indexRight = 2*index +2;
    if ( indexLeft >=sizes ) break;
    if ( indexLeft == sizes-1 || values[indexLeft] > values[indexRight] )
    {
      values[index] = values[indexLeft];
      index = indexLeft;
    }
    else
    {
      values[index] = values[indexRight];
      index = indexRight;
    }
  }
  --sizes;
  while ( index>0 )
  {
    int parentIndex = (index+1)/2 - 1;
    if ( parentIndex < 0 ) break;
    if ( values[parentIndex] >= values[index] ) break;
    swap ( values[parentIndex], values[index] );
    index = parentIndex;
  }
  return param;
}
template<class T>
T& PriorityQueue<T>::front()
{
  if (sizes> 0) return values[0];
  return dummy;
}
template<class T>
T& PriorityQueue<T>::back()
{
  if (sizes-1 > 0) return values[sizes-1];
  return dummy;
}

#endif
