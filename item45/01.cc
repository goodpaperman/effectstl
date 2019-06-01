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
  int rep = rand() % 20; 
  vector<int>::iterator it = lower_bound(ivec.begin(), ivec.end(), rep); 
  for(int i=0; i<3; ++ i)
    it = ivec.insert(it, rep);  

  cout << "ivec content: " << endl; 
  copy(ivec.begin(), ivec.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 

  int n = 0; 
  cout << "lower_bound" << endl; 
  it = lower_bound(ivec.begin(), ivec.end(), rep); 
  while(it != ivec.end() && !(rep < *it))
  {
    cout << *it << " "; 
    ++ it; 
    ++ n; 
  }

  cout << "total = " << n << endl; 
  cout << "equal_range" << endl; 
  std::pair<vector<int>::iterator, vector<int>::iterator> its = 
      equal_range(ivec.begin(), ivec.end(), rep); 
  cout << "total = " << distance(its.first, its.second) << endl; 
  while(its.first != its.second)
  {
    cout << *its.first << " "; 
    ++ its.first; 
  }

  cout << endl; 
  return 0; 
}

