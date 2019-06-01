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

class widget
{
public:
  widget() : id_(0) { }
  widget(int id) : id_(id) { }
  operator int() { return id_; } 
  bool is_certified() const { return id_ % 3 == 0; } 

private:
  int id_; 
}; 

int main()
{
  srand(time(0)); 
  vector<widget> ivec; 
  ivec.reserve(20); 
  for(int i=0; i<20; ++ i)
    ivec.push_back(i); 

  random_shuffle(ivec.begin(), ivec.end()); 
  cout << "after shuffle: " << endl; 
  copy(ivec.begin(), ivec.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 

  vector<widget>::iterator it = remove_if(ivec.begin(), ivec.end(), 
                 std::not1(std::mem_fun_ref(&widget::is_certified))); 
  cout << "after remove: " << endl; 
  copy(ivec.begin(), ivec.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 

  ivec.erase(it, ivec.end()); 
  cout << "after erase: " << endl; 
  copy(ivec.begin(), ivec.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 

  return 0; 
}

