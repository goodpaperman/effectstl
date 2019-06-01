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

bool is_odd(int x)
{ return x % 2 == 1; } 

int main()
{
  vector<int> ivec; 
  ivec.reserve(20); 
  for(int i=0; i<20; ++ i)
    ivec.push_back(i); 

  srand(time(0)); 
  random_shuffle(ivec.begin(), ivec.end()); 
  cout << "vector content: " << endl; 
  copy(ivec.begin(), ivec.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 

  vector<int>::iterator it = find_if(ivec.begin(), ivec.end(), is_odd); 
  if(it != ivec.end())
    cout << "first odd number = " << *it << endl; 

  it = find_if(ivec.begin(), ivec.end(), std::not1(std::ptr_fun(is_odd))); 
  if(it != ivec.end())
    cout << "first even number = " << *it << endl; 

  return 0; 
}

