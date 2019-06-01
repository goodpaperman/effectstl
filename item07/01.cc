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

class Widget
{
public:
  Widget() {}
  ~Widget() { cout << "Widget dtor" << endl; }
}; 

template <typename T>
class DeleteObject : std::unary_function<const T*, void> 
{
public:
  void operator()(const T *v) const { delete v; } 
}; 

int main()
{
  vector<Widget*> ivec; 
  for(int i=0; i<10; ++ i)
    ivec.push_back(new Widget()); 

  //for(int i=0; i<ivec.size(); ++ i)
  //  delete ivec[i]; 
  std::for_each(ivec.begin(), ivec.end(), DeleteObject<Widget>()); 
  return 0; 
}

