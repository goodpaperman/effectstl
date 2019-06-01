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
  hrtime hrt; 
  vector<int> ivec, ivec2, ivec3; 
  ivec.reserve(20); 
  for(int i=0; i<20; ++ i)
  {
    ivec.push_back(i); 
    ivec2.push_back(i+10); 
  }

  ivec3.reserve(20); 
  cout << "ivec content: " << endl; 
  copy(ivec.begin(), ivec.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 

  cout << "ivec2 content: " << endl; 
  copy(ivec2.begin(), ivec2.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 

  set_union(ivec.begin(), ivec.end(), ivec2.begin(), ivec2.end(), 
            back_inserter(ivec3)); 
  cout << "after set_union: " << endl; 
  copy(ivec3.begin(), ivec3.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 

  ivec3.clear(); 
  set_intersection(ivec.begin(), ivec.end(), ivec2.begin(), ivec2.end(), 
                  back_inserter(ivec3)); 
  cout << "after set_intersection: " << endl; 
  copy(ivec3.begin(), ivec3.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 

  ivec3.clear(); 
  set_difference(ivec.begin(), ivec.end(), ivec2.begin(), ivec2.end(), 
                 back_inserter(ivec3)); 
  cout << "after set_difference: " << endl; 
  copy(ivec3.begin(), ivec3.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 

  ivec3.clear(); 
  set_difference(ivec2.begin(), ivec2.end(), ivec.begin(), ivec.end(), 
                 back_inserter(ivec3)); 
  cout << "after set_difference(2): " << endl; 
  copy(ivec3.begin(), ivec3.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 

  ivec3.clear(); 
  set_symmetric_difference(ivec.begin(), ivec.end(), ivec2.begin(), ivec2.end(),
                           back_inserter(ivec3)); 
  cout << "after set_symmetric_difference: " << endl; 
  copy(ivec3.begin(), ivec3.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 

  ivec3.clear(); 
  random_shuffle(ivec.begin(), ivec.end()); 
  random_shuffle(ivec2.begin(), ivec2.end()); 
  set_union(ivec.begin(), ivec.end(), ivec2.begin(), ivec2.end(), 
            back_inserter(ivec3)); 
  cout << "after set_union(random): " << endl; 
  copy(ivec3.begin(), ivec3.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 

  return 0; 
}

