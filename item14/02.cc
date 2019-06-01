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
using std::map;  
using std::string; 
using std::cout; 
using std::endl; 
using std::ifstream; 
using std::copy; 
using std::auto_ptr; 



int main()
{
  hrtime hrt; 
  vector<int> ivec; 
  //ivec.reserve(1000); 
  for(int i=0; i<1000; ++ i)
  {
    hrt.start(); 
    ivec.push_back(i); 
    hrt.end(); 
    cout << ivec.size() << " " 
         << ivec.capacity() << " " 
         << hrt.elapse() << endl; 
  }

  return 0; 
}

