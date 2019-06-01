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
using std::istream_iterator; 
using std::vector; 
using std::list;
using std::deque;  
using std::set;
using std::multiset; 
using std::map;  
using std::string; 
using std::cin; 
using std::cout; 
using std::endl; 
using std::ifstream; 
using std::copy; 
using std::auto_ptr; 


int main()
{
  set<int> iset; 
  vector<int> ivec; 
  ivec.reserve(1000000); 
  for(int i=0; i<1000000; ++ i)
  {
    ivec.push_back(i); 
    iset.insert(i); 
  }

  int target = 0; 
  hrtime hrt; 
  sort(ivec.begin(), ivec.end()); 

  target = 9999; 
  hrt.start(); 
  set<int>::iterator sit = iset.find(target); 
  hrt.end(); 
  if(sit != iset.end())
  {
    cout << "find " << target << " in set" << endl; 
    hrt.report(""); 
  }
 
  hrt.start();  
  vector<int>::iterator vit = lower_bound(ivec.begin(), ivec.end(), target); 
  hrt.end(); 
  if(vit != ivec.end() && !(target < *vit))
  {
    cout << "find " << target << " in vec" << endl; 
    hrt.report(""); 
  }

  return 0; 
}

