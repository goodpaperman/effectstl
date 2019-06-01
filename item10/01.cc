#include <iostream>
#include <fstream> 
#include <vector> 
#include <list> 
#include <deque>
#include <set> 
#include <string> 
#include <iterator> 
#include <algorithm> 
#include <functional> 
#include <memory> 
#include <sys/time.h> 
#include "../hrtime.h"

using std::ostream_iterator; 
using std::istream_iterator; 
using std::vector; 
using std::list;
using std::deque;  
using std::set; 
using std::string; 
using std::cout; 
using std::endl; 
using std::ifstream; 
using std::copy; 
using std::auto_ptr; 


template <typename T>
class stl_allocator// : public std::allocator<T>
{
public:
  typedef T* pointer; 
  typedef const T* const_pointer; 
  typedef T& reference; 
  typedef const T& const_reference; 
  typedef ptrdiff_t difference_type; 
  typedef size_t size_type; 
  typedef T value_type; 

  template <typename U>
  struct rebind {
    typedef stl_allocator<U> other; 
  }; 

  stl_allocator() {}
  stl_allocator(const stl_allocator& alloc) {}
  template <typename U>
  stl_allocator(const stl_allocator<U>& alloc) {} 
  ~stl_allocator() {}

  template <typename U>
  bool operator== (const stl_allocator<U> &rhs) { return true; } 

  template <typename U>
  bool operator!= (const stl_allocator<U> &rhs) { return false; } 

  void construct(pointer p, int n) { cout << "construct " << n << endl; }  
  void destroy(pointer p) { cout << "destroy" << endl; }
  pointer allocate(size_type n) { 
    cout << "allocate " << n << endl; 
    return (pointer)new char[n*sizeof(T)](); }   
  void deallocate(pointer p, size_type n) { 
    cout << "deallocate " << n << endl; 
    delete []p; }
}; 

int main()
{
  cout << "vector test" << endl; 
  vector<int, stl_allocator<int> > ivec; 
  for(int i=0; i<10; ++ i)
    ivec.push_back(i); 

  cout << endl; 
  cout << "list test" << endl; 
  list<int, stl_allocator<int> > ilist; 
  for(int i=0; i<10; ++ i)
    ilist.push_back(i); 
    //ilist.insert(ilist.end(), i); 


  //cout << endl; 
  //cout << "set test" << endl; 
  //set<int, stl_allocator<int> > iset; 
  //for(int i=0; i<10; ++ i)
  //  iset.insert(i); 

  return 0; 
}

