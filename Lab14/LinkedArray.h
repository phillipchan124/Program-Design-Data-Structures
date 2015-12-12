// Lab 6a, Write A Linked Array Class Template
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)
#ifndef LinkedArray_h
#define LinkedArray_h

#include<vector>
using namespace std;

template<class T>
class LinkedArray
{
private:
  static const int INIT_CAP = 0;
  struct Node
  {
    T value;
    bool inUse;
    Node* next;
  };
  Node* start;
  Node* end;
  int cap;
  T dummy;
  mutable int sizes;
  mutable Node* lastP;
  mutable int lastIndex;
public:
  LinkedArray( int=INIT_CAP ); // default constructor
  ~LinkedArray(); // destructor
  LinkedArray( const LinkedArray<T>& ); // copy constructor
  LinkedArray<T>& operator=( const LinkedArray<T>& ); // assignment operator
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
LinkedArray<T>::LinkedArray( int init_cap )
{
  cap = init_cap;
  start = NULL;
  end = NULL;
  sizes = 0;
  int i=0;
  for (i = 0; i < cap; i++)
  {
    Node* node = new Node;
    node->inUse = false;
    node->next = 0;
    if (end) end->next = node;
    else start = node;
    end = node;
  }
  lastP = NULL;
  lastIndex = -1;
}
template <class T>
LinkedArray<T>::~LinkedArray()
{
  Node* p;
  while (start)
  {
    p = start->next;
    delete start;
    start = p;
  }
  end = 0;
}
template <class T>
LinkedArray<T>::LinkedArray( const LinkedArray<T>& a)
{
  cap = a.cap;
  sizes = a.sizes;
  start = NULL;
  end = NULL;
  lastP = NULL;
  lastIndex = -1;
  
  Node* p;
  for ( p = a.start ; p ; p=p->next )
  {
    Node* node = new Node;
    node->value = p->value;
    node->inUse = p->inUse;
    node->next = 0;
    if (end) end->next = node;
    else start = node;
    end = node;
    if (p==lastP) lastP = node;
  }
}
template <class T>
LinkedArray<T>& LinkedArray<T>::operator=( const LinkedArray<T>& a)
{
  if ( this == &a ) return *this;
  
  while (start)
  {
    Node* p = start->next;
    delete start;
    start = p;
  }
  end = 0;

  Node* p;
  
  start = 0;
  end = 0;
  cap = a.cap;
  sizes = a.sizes;
  lastP = NULL;
  lastIndex = -1;
  
  for ( p = a.start ; p ; p=p->next )
  {
    Node* node = new Node;
    node->value = p->value;
    node->inUse = p->inUse;
    node->next = 0;
    if (end) end->next = node;
    else start = node;
    end = node;
  }
  
  return *this;
}
template <class T>
T& LinkedArray<T>::operator[](int index)
{
  if ( index < 0 ) return dummy;
  
  Node* p = start;
  int count = 0;
  
  if ( index >= cap )
  {
    p = end;
    for (int i = cap; i <= index; i++)
    {
      Node* node = new Node;
      node->inUse = false;
      node->next = 0;
      end->next = node;
      end = node;
    }
    
    Node* node = new Node;
    node->inUse = true;
    node->next = 0;
    
    cap = index+1;
  }
  
  if (lastIndex != -1 && lastIndex <= index)
  {
    p = lastP;
    count = lastIndex;
  }
  for (; p; p = p->next, count++)
    if (count == index)
      break;
  lastP = p;
  lastIndex = index;
  
  if (!p->inUse && index > -1 && index < cap)
  {
    p->inUse = true;
    sizes++;
  }
  
  return p->value;
}
template <class T>
T LinkedArray<T>::operator[](int index) const
{
  if (index < 0 || index >= cap) return dummy;
  
  const Node* p = start;
  int count = 0;
  
  if (lastIndex != -1 && lastIndex <= index)
  {
    p = lastP;
    count = lastIndex;
  }
  for (; p; p = p->next, count++)
    if (count == index)
      break;
  lastP = (Node*)p;
  lastIndex = index;

  if (p->inUse == false) return dummy;
  return p->value;
}
template <class T>
int LinkedArray<T>::size() const
{
  return sizes;
}
template <class T>
int LinkedArray<T>::capacity() const
{
  return cap;
}
template <class T>
bool LinkedArray<T>::containsKey(int index) const
{
  if (index < 0 || index >= cap) return false;
  
  const Node* p = start;
  int count = 0;
  
  if (lastIndex != -1 && lastIndex <= index)
  {
    p = lastP;
    count = lastIndex;
  }
  for (; p; p = p->next, count++)
    if (count == index)
      break;
  lastP = (Node*)p;
  lastIndex = index;
  
  return lastP->inUse;
}
template <class T>
void LinkedArray<T>::deleteKey(int index)
{
  if (index < 0) return;
  if (index >= cap) return;
  
  Node* p = start;
  int count = 0;
  
  for (; p; p = p->next, count++)
    if (count == index)
      break;
  
  if (p->inUse) sizes--;
  p->inUse = false;
}
template <class T>
vector<int> LinkedArray<T>::keys() const
{
  vector<int> v;
  
  Node* p = start;
  int count = 0;
  
  for (; p; p = p->next, count++)
    if (containsKey(count))
      v.push_back(p->value);

  return v;
}
template <class T>
void LinkedArray<T>::clear()
{
  int count = 0;
  sizes = 0;
  Node* p = start;
  
  for (; p; p = p->next, count++)
    p->inUse = false;
}

#endif