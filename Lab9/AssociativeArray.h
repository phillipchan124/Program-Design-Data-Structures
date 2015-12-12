// Lab 9, Write, Test and Apply The AssociativeArray Template
// Programmer: Kwun Hang Chan
// Editor(s) used: Xcode
// Compliers(s) used: Apple LLVM version 6.1.0 (clang-602.0.53) (based on LLVM 3.6.0svn)

#ifndef AssociativeArray_h
#define AssociativeArray_h

#include<vector>
using namespace std;

template<class T, class U>
class AssociativeArray
{
private:
  static const int INIT_CAP = 0;
  struct Node
  {
    T value;
    U key;
    bool inUse;
    Node* next;
  };
  Node* start;
  Node* end;
  int cap;
  T dummy;
  mutable int sizes;
public:
  AssociativeArray( int=INIT_CAP ); // default constructor
  ~AssociativeArray(); // destructor
  AssociativeArray( const AssociativeArray<T, U>& ); // copy constructor
  AssociativeArray<T, U>& operator=( const AssociativeArray<T, U>& ); // assignment operator
  T& operator[](const U& key);
  T operator[](const U& key) const;
  int size() const; // #of keys "in use", initially zero
  int capacity() const;
  bool containsKey(const U&) const;
  void deleteKey(const U&); // set "in use" to false
  vector<U> keys() const; // all "in use" keys
  void clear();
};
template <class T, class U>
AssociativeArray<T, U>::AssociativeArray( int init_cap )
{
  cap = init_cap;
  start = NULL;
  end = NULL;
  sizes = 0;
  for (int i = 0; i < cap; i++)
  {
    Node* node = new Node;
    node->inUse = false;
    node->next = 0;
    if (end) end->next = node;
    else start = node;
    end = node;
  }
}
template <class T, class U>
AssociativeArray<T, U>::~AssociativeArray()
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
template <class T, class U>
AssociativeArray<T, U>::AssociativeArray( const AssociativeArray<T, U>& a)
{
  cap = a.cap;
  sizes = a.sizes;
  start = NULL;
  end = NULL;
  
  Node* p;
  for ( p = a.start ; p ; p=p->next )
  {
    Node* node = new Node;
    node->value = p->value;
    node->inUse = p->inUse;
    node->key = p->key;
    node->next = 0;
    if (end) end->next = node;
    else start = node;
    end = node;
  }
}
template <class T, class U>
AssociativeArray<T, U>& AssociativeArray<T, U>::operator=( const AssociativeArray<T, U>& a)
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
  
  for ( p = a.start ; p ; p=p->next )
  {
    Node* node = new Node;
    node->value = p->value;
    node->inUse = p->inUse;
    node->key = p->key;
    node->next = 0;
    if (end) end->next = node;
    else start = node;
    end = node;
  }
  
  return *this;
}
template <class T, class U>
T& AssociativeArray<T, U>::operator[](const U& key)
{
  for (Node* p = start; p; p = p->next)
    if ( p->inUse == true && p->key == key)
      return p->value;
  
  for (Node* p = start; p; p = p->next)
    if ( p->inUse == false)
    {
      p->key = key;
      p->inUse = true;
      sizes++;
      return p->value;
    }
  Node* node = new Node;
  node->inUse = true;
  node->key = key;
  node->next = 0;
  if (end) end->next = node;
  else start = node;
  end = node;
  cap++;
  sizes++;
  return node->value;
}
template <class T, class U>
T AssociativeArray<T, U>::operator[](const U& key) const
{
  for (Node* p = start; p; p = p->next)
    if ( p->inUse == true && p->key == key)
      return p->value;
  return dummy;
}
template <class T, class U>
int AssociativeArray<T, U>::size() const
{
  return sizes;
}
template <class T, class U>
int AssociativeArray<T, U>::capacity() const
{
  return cap;
}
template <class T, class U>
bool AssociativeArray<T, U>::containsKey(const U& key) const
{
  for (Node* p = start; p; p = p->next)
    if (p->key == key)
      return p->inUse;
  return false;
}
template <class T, class U>
void AssociativeArray<T, U>::deleteKey(const U& key)
{
  for (Node* p = start; p; p = p->next)
    if ( p->inUse == true && p->key == key)
    {
      p->inUse = false;
      sizes--;
    }
}
template <class T, class U>
vector<U> AssociativeArray<T, U>::keys() const
{
  vector<U> v;
  for (Node* p = start; p; p = p->next)
    if (p->inUse) v.push_back(p->key);
  return v;
}
template <class T, class U>
void AssociativeArray<T, U>::clear()
{
  sizes = 0;
  for (Node* p = start; p; p = p->next)
    p->inUse = false;
}

#endif /* AssociativeArray_h */
