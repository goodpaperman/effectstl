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
using std::multimap; 
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
  vector<int> ivec; 
  list<int> ilist; 
  ivec.reserve(10000); 
  for(int i=0; i<10000; ++ i)
  {
    ivec.push_back(i); 
    ilist.push_back(i); 
  }

  hrtime hrt; 
  vector<int>::const_iterator cvit = --ivec.end(); 
  cout << *cvit << endl; 
  vector<int>::iterator vit = ivec.begin(); 
  hrt.start(); 
  std::advance(vit, std::distance<vector<int>::const_iterator>(vit, cvit)); 
  hrt.end(); 
  hrt.report("vector iterator test "); 
  cout << *vit << endl; 

  list<int>::const_iterator clit = --ilist.end(); 
  cout << *clit << endl; 
  list<int>::iterator lit = ilist.begin(); 
  hrt.start(); 
  std::advance(lit, std::distance<list<int>::const_iterator>(lit, clit)); 
  hrt.end(); 
  hrt.report("list iterator test "); 
  cout << *lit << endl; 

  return 0; 
}

