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
  list<int> ilist; 
  for(int i=0; i<1000000; ++ i)
    ilist.push_back(i); 

  hrtime hrt; 
  srand(time(0)); 
  int t = rand() % 1000000; 
  cout << "remove " << t << endl; 
  list<int>::iterator it; 

  hrt.start(); 
  ilist.remove(t); 
  hrt.end(); 
  hrt.report("list::remove "); 
  cout << "result = " << ilist.size() << endl; 

  ++ t; 
  hrt.start(); 
  ilist.erase(remove(ilist.begin(), ilist.end(), t), ilist.end()); 
  hrt.end(); 
  hrt.report("std::remove "); 
  cout << "result = " << ilist.size() << endl; 

  cout << "unique " << endl; 
  hrt.start(); 
  ilist.unique(); 
  hrt.end(); 
  hrt.report("list::unique"); 

  hrt.start(); 
  ilist.erase(unique(ilist.begin(), ilist.end()), ilist.end()); 
  hrt.end(); 
  hrt.report("std::unique"); 

  cout << "reverse " << endl; 
  hrt.start(); 
  ilist.reverse(); 
  hrt.end(); 
  hrt.report("ilist::reverse"); 

  hrt.start(); 
  reverse(ilist.begin(), ilist.end()); 
  hrt.end(); 
  hrt.report("std::reverse"); 
  
  return 0; 
}

