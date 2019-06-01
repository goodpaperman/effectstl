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
  hrtime hrt; 
  map<int, int> imap; 
  hrt.start(); 
  for(int i=0; i<1000000; ++ i)
    imap[i] = i; 
  hrt.end(); 
  hrt.report("imap[i] "); 

  map<int, int>().swap(imap); 
  hrt.start(); 
  for(int i=0; i<1000000; ++ i)
    imap.insert(std::make_pair(i, i)); 
  hrt.end(); 
  hrt.report("imap.insert "); 

  return 0; 
}

