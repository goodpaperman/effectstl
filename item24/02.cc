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

class widget
{
public:
  widget() { }
  widget(int i) { }
  widget(const widget &w) { 
    for(int i=0; i<4096; ++ i)
      mess[i] = w.mess[i]; 
  }
  widget& operator= (const widget &w) {
    for(int i=0; i<4096; ++ i)
      mess[i] = w.mess[i]; 
    return *this; 
  }

private:
  char mess[4096]; 
}; 

int main()
{
  hrtime hrt; 
  map<int, widget> imap; 
  hrt.start(); 
  for(int i=0; i<10000; ++ i)
    imap[i] = i; 
  hrt.end(); 
  hrt.report("imap[i] "); 

  hrt.start(); 
  for(int i=0; i<10000; ++ i)
    imap.insert(map<int, widget>::value_type(i, i)).first->second = i;
  hrt.end(); 
  hrt.report("imap.insert.update "); 

  map<int, widget>().swap(imap); 
  hrt.start(); 
  for(int i=0; i<10000; ++ i)
    imap.insert(map<int, widget>::value_type(i, i)); 
    //imap.insert(std::make_pair(i, i)); 
  hrt.end(); 
  hrt.report("imap.insert "); 

  hrt.start(); 
  for(int i=0; i<10000; ++ i)
    imap[i] = i; 
  hrt.end(); 
  hrt.report("imap[i].update "); 

  return 0; 
}

