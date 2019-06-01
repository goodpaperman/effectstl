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



int main()
{
  string str; 
  str.reserve(100); 
  for(int i=0; i<50; ++ i)
    str.push_back(i); 
  cout << "size = " << str.size()
       << " capacity = " << str.capacity() 
       << endl; 

  string().swap(str); 
  cout << "after swap: " << endl
       << "size = " << str.size() 
       << " capacity = " << str.capacity() 
       << endl; 
  return 0; 
}

