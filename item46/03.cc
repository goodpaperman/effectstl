#include <iostream>
#include <fstream> 
#include <sstream> 
#include <vector> 
#include <list> 
#include <deque>
#include <set> 
#include <map> 
#include <string> 
#include <iterator> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <memory> 
#include <sys/time.h> 
#include "../hrtime.h"

using std::ostream_iterator; 
using std::ostreambuf_iterator; 
using std::istream_iterator; 
using std::istreambuf_iterator; 
using std::istringstream; 
using std::ostringstream; 
using std::vector; 
using std::list;
using std::deque;  
using std::set;
using std::multimap; 
using std::map;  
using std::string; 
using std::cin; 
using std::cout; 
using std::endl; 
using std::ostream; 
using std::ofstream; 
using std::copy; 
using std::auto_ptr; 

template <typename T>
T averge(T lhs, T rhs)
{ return (lhs + rhs) / 2; }

int main()
{
  vector<int> ivec, ivec2; 
  ivec.reserve(20); 
  ivec2.reserve(20); 
  for(int i=0; i<20; ++ i)
  {
    ivec.push_back(i); 
    ivec2.push_back(i+10); 
  }

  copy(ivec.begin(), ivec.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 
  copy(ivec2.begin(), ivec2.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 

  transform(ivec.begin(), ivec.end(), ivec2.begin(), 
            ostream_iterator<int>(cout, " "), 
            averge<int>); 
  cout << endl; 

  return 0; 
}

