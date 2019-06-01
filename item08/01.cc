#include <iostream>
#include <fstream> 
#include <vector> 
#include <list> 
#include <deque>
#include <set> 
#include <string> 
#include <iterator> 
#include <algorithm> 
#include <functional> 
#include <sys/time.h> 
#include "../hrtime.h"

using std::ostream_iterator; 
using std::istream_iterator; 
using std::vector; 
using std::list;
using std::deque;  
using std::set; 
using std::string; 
using std::cout; 
using std::endl; 
using std::ifstream; 
using std::copy; 
using std::auto_ptr; 

class Widget
{
public:
  Widget() {}
  ~Widget() { cout << "Widget dtor" << endl; }
  void destroy() { delete this; } 
}; 

int main()
{

  vector<auto_ptr<Widget> > ivec; 
  for(int i=0; i<10; ++ i)
  {
    auto_ptr<Widget> pw(new Widget()); 
    ivec.push_back(pw); 
  }

  //std::for_each(ivec.begin(), ivec.end(), std::mem_fun(&Widget::destroy)); 
  return 0; 
}

