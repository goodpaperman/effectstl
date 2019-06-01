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


int main()
{
  vector<int> ivec; 
  ivec.reserve(20); 
  for(int i=0; i<20; ++ i)
    ivec.push_back(i); 

  srand(time(0));
  int rep = 0; 
  vector<int>::iterator it; 
  for(int i=0; i<3; ++ i)
  { 
    rep = rand() % 20; 
    it = lower_bound(ivec.begin(), ivec.end(), rep); 
    if(it != ivec.end()); 
      ivec.erase(it);  
  }

  cout << "ivec content: " << endl; 
  copy(ivec.begin(), ivec.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 

  cout << "lower_bound " << rep << endl; 
  it = lower_bound(ivec.begin(), ivec.end(), rep); 
  if(it != ivec.end())
    cout << *it << endl; 
  else 
    cout << "end" << endl; 

  cout << "upper_bound " << rep << endl; 
  it = upper_bound(ivec.begin(), ivec.end(), rep); 
  if(it != ivec.end()) 
    cout << *it << endl; 
  else 
    cout << "end" << endl; 

  cout << "equal_range " << rep << endl; 
  std::pair<vector<int>::iterator, vector<int>::iterator> its = 
      equal_range(ivec.begin(), ivec.end(), rep); 
  cout << "total = " << distance(its.first, its.second) << endl; 
  if(its.first != ivec.end()) 
    cout << *its.first << endl; 
  else 
    cout << "end" << endl; 

  if(its.second != ivec.end())
    cout << *its.second << endl; 
  else 
    cout << "end" << endl; 

  return 0; 
}

