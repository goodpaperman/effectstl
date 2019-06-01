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
  ivec.reserve(8192); 
  for(int i=0; i<8192; ++ i)
  {
    ivec.push_back(i); 
    ivec2.push_back(i+8192/2); 
  }

  ivec3.reserve(8192); 

  hrt.start(); 
  set_union(ivec.begin(), ivec.end(), ivec2.begin(), ivec2.end(), 
            back_inserter(ivec3)); 
  hrt.end(); 
  hrt.report("set_union sorted "); 
  cout << "size = " << ivec3.size() << endl; 

  ivec3.clear(); 
  hrt.start(); 
  set_intersection(ivec.begin(), ivec.end(), ivec2.begin(), ivec2.end(), 
                  back_inserter(ivec3)); 
  hrt.end(); 
  hrt.report("set_intersection sorted "); 
  cout << "size = " << ivec3.size() << endl; 

  ivec3.clear(); 
  hrt.start(); 
  set_difference(ivec.begin(), ivec.end(), ivec2.begin(), ivec2.end(), 
                 back_inserter(ivec3)); 
  hrt.end(); 
  hrt.report("set_difference sorted "); 
  cout << "size = " << ivec3.size() << endl; 

  ivec3.clear(); 
  hrt.start(); 
  set_symmetric_difference(ivec.begin(), ivec.end(), ivec2.begin(), ivec2.end(),
                           back_inserter(ivec3)); 
  hrt.end(); 
  hrt.report("set_symmetric_difference sorted "); 
  cout << "size = " << ivec3.size() << endl; 


  srand(time(0)); 
  random_shuffle(ivec.begin(), ivec.end()); 
  random_shuffle(ivec2.begin(), ivec2.end()); 
  ivec3.clear(); 

  hrt.start(); 
  set_union(ivec.begin(), ivec.end(), ivec2.begin(), ivec2.end(),
            back_inserter(ivec3));
  hrt.end(); 
  hrt.report("set_union unsorted "); 
  cout << "size = " << ivec3.size() << endl; 

  ivec3.clear();
  hrt.start(); 
  set_intersection(ivec.begin(), ivec.end(), ivec2.begin(), ivec2.end(),
                  back_inserter(ivec3));
  hrt.end(); 
  hrt.report("set_intersection unsorted "); 
  cout << "size = " << ivec3.size() << endl; 

  ivec3.clear();
  hrt.start(); 
  set_difference(ivec.begin(), ivec.end(), ivec2.begin(), ivec2.end(),
                 back_inserter(ivec3));
  hrt.end(); 
  hrt.report("set_difference unsorted "); 
  cout << "size = " << ivec3.size() << endl; 

  ivec3.clear();
  hrt.start(); 
  set_symmetric_difference(ivec.begin(), ivec.end(), ivec2.begin(), ivec2.end(),
                           back_inserter(ivec3));
  hrt.end(); 
  hrt.report("set_symmetric_difference unsorted "); 
  cout << "size = " << ivec3.size() << endl; 

  return 0; 
}

