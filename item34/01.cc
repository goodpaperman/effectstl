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
  //set<int> iset; 
  //for(int i=0; i<20; ++ i)
  //  iset.insert(i, i); 
  //remove(iset.begin(), iset.end(), 5); 

  hrtime hrt; 
  vector<int> ivec; 
  list<int> ilist;
  ivec.reserve(8192); 
  for(int i=0; i<8192; ++ i)
    ivec.push_back(i); 

  ilist.assign(ivec.begin(), ivec.end()); 

  hrt.start(); 
  bool ret = binary_search(ivec.begin(), ivec.end(), 0); 
  hrt.end(); 
  hrt.report("binary_search vector "); 
  cout << "ret = " << ret << endl; 

  hrt.start(); 
  ret = binary_search(ilist.begin(), ilist.end(), 0); 
  hrt.end(); 
  hrt.report("binary_search list "); 
  cout << "ret = " << ret << endl; 

  return 0; 
}

