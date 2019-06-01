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


void print(const char *sz)
{
  cout << sz << endl; 
}

struct str_ptr_less : public std::binary_function<char*, char*, bool> 
{
  bool operator() (const char *lhs, const char *rhs) {
    return strcmp(lhs, rhs) < 0; 
  }
}; 

int main()
{
  set<char*, str_ptr_less> szset; 
  {
  szset.insert("Anteater"); 
  szset.insert("Wombat"); 
  szset.insert("Lemur"); 
  szset.insert("Penguin"); 
  }

  //for_each(szset.begin(), szset.end(), print);   
  copy(szset.begin(), szset.end(), ostream_iterator<char*>(cout, "\n")); 

  return 0; 
}

