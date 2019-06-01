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


int main()
{
  vector<int> ivec, ivec2, ivec3; 
  ivec.reserve(20); 
  ivec2.reserve(20); 
  ivec3.reserve(40); 
  for(int i=0; i<20; ++ i)
  {
    ivec.push_back(i); 
    ivec2.push_back(i+10); 
  }

  cout << "ivec content: " << endl; 
  copy(ivec.begin(), ivec.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 

  cout << "ivec2 content: " << endl; 
  copy(ivec2.begin(), ivec2.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 

  merge(ivec.begin(), ivec.end(), ivec2.begin(), ivec2.end(), 
        back_inserter(ivec3)); 
  cout << "after merge: " << endl; 
  copy(ivec3.begin(), ivec3.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 

  ivec3.clear(); 
  random_shuffle(ivec.begin(), ivec.end()); 
  random_shuffle(ivec2.begin(), ivec2.end()); 

  merge(ivec.begin(), ivec.end(), ivec2.begin(), ivec2.end(), 
        back_inserter(ivec3)); 
  cout << "after merge: " << endl; 
  copy(ivec3.begin(), ivec3.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 
  return 0; 
}

