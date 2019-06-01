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

class widget
{
public: 
  void redraw() const { cout << "redraw" << endl; } 
  void reset(bool clear) const { cout << "reset" << endl; } 
  void adjust(int x, int y) const { cout << "adjust" << endl; } 
}; 

int main()
{
  vector<widget> wvec; 
  wvec.reserve(20); 
  for(int i=0; i<20; ++ i)
    wvec.push_back(widget()); 

  for_each(wvec.begin(), wvec.end(), std::mem_fun_ref(&widget::redraw)); 
  cout << endl; 

  for_each(wvec.begin(), wvec.end(), 
           std::bind2nd(std::mem_fun_ref(&widget::reset), true)); 
  cout << endl; 

  //for_each(wvec.begin(), wvec.end(), 
  //        std::bind2nd(std::mem_fun_ref(&widget::adjust), 2)); 

  //for_each(wvec.begin(), wvec.end(), 
  //        std::mem_fun_ref(&widget::reset)); 
  return 0; 
}

