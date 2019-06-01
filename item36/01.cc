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
using std::ostreambuf_iterator; 
using std::istream_iterator; 
using std::istreambuf_iterator; 
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
using std::ofstream; 
using std::copy; 
using std::auto_ptr; 

bool is_odd(int x)
{
  return x % 2 == 1; 
}

template <typename InputIterator, 
          typename OutputIterator, 
          typename Predicate>
OutputIterator copy_if(InputIterator begin, 
                       InputIterator end, 
                       OutputIterator destbegin, 
                       Predicate pre)
{
  return remove_copy_if(begin, end, destbegin, std::not1(pre)); 
}

int main()
{
  vector<int> ivec; 
  ivec.reserve(20); 
  for(int i=0; i<20; ++ i)
    ivec.push_back(i); 

  vector<int> ivec2; 
  ivec2.reserve(20); 
  copy_if(ivec.begin(), ivec.end(), back_inserter(ivec2), std::ptr_fun(is_odd)); 

  cout << "after copy_if" << endl; 
  copy(ivec2.begin(), ivec2.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 
  return 0; 
}

