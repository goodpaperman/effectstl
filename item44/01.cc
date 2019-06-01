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
  set<int> iset; 
  for(int i=0; i<1000000; ++ i)
    iset.insert(i); 

  hrtime hrt; 
  srand(time(0)); 
  int t = rand() % 1000000; 
  cout << "find " << t << endl; 
  set<int>::iterator it; 

  hrt.start(); 
  it = iset.find(t); 
  hrt.end(); 
  hrt.report("set::find "); 
  cout << "result = " << *it << endl; 

  hrt.start(); 
  it = find(iset.begin(), iset.end(), t); 
  hrt.end(); 
  hrt.report("std::find "); 
  cout << "result = " << *it << endl; 

  cout << "lower_bound " << t << endl; 
  hrt.start(); 
  it = iset.lower_bound(t); 
  hrt.end(); 
  hrt.report("set::lower_bound"); 
  cout << "result = " << *it << endl; 

  hrt.start(); 
  it = lower_bound(iset.begin(), iset.end(), t); 
  hrt.end(); 
  hrt.report("std::lower_bound"); 
  cout << "result = " << *it << endl; 

  cout << "count " << t << endl; 
  hrt.start(); 
  int n = iset.count(t); 
  hrt.end(); 
  hrt.report("set::count"); 
  cout << "result = " << n << endl; 

  hrt.start(); 
  n = count(iset.begin(), iset.end(), t); 
  hrt.end(); 
  hrt.report("std::count"); 
  cout << "result = " << n << endl;
  
  return 0; 
}

