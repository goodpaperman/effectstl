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
using std::cin; 
using std::cout; 
using std::endl; 
using std::ifstream; 
using std::copy; 
using std::auto_ptr; 



int main()
{
  vector<bool> bvec; 
  for(int i=0; i<100; ++ i)
    bvec.push_back(i%2 == 0); 

  cout << "size = " << bvec.size() 
       << " capacity = " << bvec.capacity() 
       << " sizeof(bvec) = " << sizeof(bvec) 
       << endl; 
  //bool *pb = &bvec[32];   

  bvec[32] = !bvec[32]; 
  copy(bvec.begin(), bvec.end(), ostream_iterator<bool>(cout, " ")); 
  cout << endl; 
  return 0; 
}

