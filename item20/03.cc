#include <iostream>
#include <fstream> 
#include <vector> 
#include <list> 
#include <deque>
#include <set> 
#include <map> 
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
using std::map;  
using std::string; 
using std::cin; 
using std::cout; 
using std::endl; 
using std::ifstream; 
using std::copy; 
using std::auto_ptr; 


void print(string *sz)
{
  cout << *sz << endl; 
}

void destroy(string *sz)
{
  delete sz; 
}

class def_ptr
{
public:
  template <typename T>
  const T& operator() (const T *rhs) { return *rhs; }
}; 

class def_less
{
public:
  template <typename T>
  bool operator() (const T *lhs, const T *rhs) {
    return *lhs < *rhs; 
  }
}; 

int main()
{
  set<string*, def_less> szset; 
  szset.insert(new string("Anteater")); 
  szset.insert(new string("Wombat")); 
  szset.insert(new string("Lemur")); 
  szset.insert(new string("Penguin")); 

  for_each(szset.begin(), szset.end(), print);   
  //copy(szset.begin(), szset.end(), ostream_iterator<char*>(cout, "\n")); 
  transform(szset.begin(), szset.end(), 
            ostream_iterator<string>(cout, "\n"), 
            def_ptr()); 

  for_each(szset.begin(), szset.end(), destroy); 
  return 0; 
}

