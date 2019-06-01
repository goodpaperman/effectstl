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
#include <ext/functional> 
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


int main()
{
  vector<int> ivec;
  ivec.reserve(20); 
  for(int i=0; i<20; ++ i)
    ivec.push_back(i); 

  srand(time(0)); 
  random_shuffle(ivec.begin(), ivec.end()); 
  cout << "after shuffle: " << endl; 
  copy(ivec.begin(), ivec.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 

  int x = rand() % 20; 
  int y = rand() % 20; 
  if(x > y) std::swap(x, y); 
  cout << "find first value in (" << x << "," << y << ")" << endl; 
  vector<int>::iterator it = find_if(ivec.begin(), ivec.end(), 
                             __gnu_cxx::compose2(std::logical_and<bool>(), 
                             std::bind2nd(std::greater_equal<int>(), x), 
                             std::bind2nd(std::less<int>(), y))); 
  if(it != ivec.end())
    cout << *it << endl; 
  else 
    cout << "not find" << endl; 
  return 0; 
}

