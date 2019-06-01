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

class mode_n : public std::binary_function<int, int, bool> 
{
public:
  bool operator()(int lhs, int rhs) const
  { return rhs == 0 ? true : lhs % rhs == 0; }
}; 


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

  vector<int>::iterator it = find_if(ivec.begin(), ivec.end(), 
                                    std::bind2nd(mode_n(), 3)); 
  if(it != ivec.end())
    cout << "first x%3 = " << *it << endl; 

  it = find_if(ivec.begin(), ivec.end(), 
         std::bind2nd(mode_n(), 5)); 
  if(it != ivec.end())
    cout << "first x%5 = " << *it << endl; 

  it = find_if(ivec.begin(), ivec.end(), 
               std::bind1st(mode_n(), 21)); 
  if(it != ivec.end())
    cout << "first 21%x = " << *it << endl; 

  it = find_if(ivec.begin(), ivec.end(), 
               std::bind1st(mode_n(), 35)); 
  if(it != ivec.end())
    cout << "first 35%x = " << *it << endl; 

  return 0; 
}

