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

template <typename map_type, 
          typename key_type, 
          typename value_type>
typename map_type::iterator e_add_or_update(
          map_type &m, 
          const key_type &k, 
          const value_type &v)
{
  typename map_type::iterator lb = m.lower_bound(k); 
  if(lb != m.end() && 
     !(m.key_comp()(k, lb->first)))
  {
    lb->second = v; 
    return lb; 
  }
  else
  {
    return m.insert(lb, typename map_type::value_type(k, v)); 
  }
}

int main()
{
  hrtime hrt; 
  map<int, widget> imap; 
  hrt.start(); 
  for(int i=0; i<10000; ++ i)
    imap[i] = i; 
  hrt.end(); 
  hrt.report("imap[i] insert"); 

  hrt.start(); 
  for(int i=0; i<10000; ++ i)
    imap[i]  = i;
  hrt.end(); 
  hrt.report("imap[i] update "); 

  map<int, widget>().swap(imap); 
  hrt.start(); 
  for(int i=0; i<10000; ++ i)
    imap.insert(map<int, widget>::value_type(i, i)); 
    //imap.insert(std::make_pair(i, i)); 
  hrt.end(); 
  hrt.report("imap.insert "); 

  map<int, widget>().swap(imap); 
  hrt.start(); 
  for(int i=0; i<10000; ++ i)
    e_add_or_update(imap, i, i); 
  hrt.end(); 
  hrt.report("e_add "); 

  hrt.start(); 
  for(int i=0; i<10000; ++ i)
    e_add_or_update(imap, i, i); 
  hrt.end(); 
  hrt.report("e_update ");   

  return 0; 
}

