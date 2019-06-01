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
  vector<int> ivec; 
  ivec.reserve(10); 
  for(int i=0; i<10; ++ i)
    ivec.push_back(i); 

  vector<int>::iterator it = find(ivec.begin(), ivec.end(), 5);
  vector<int>::const_iterator cit = it; 
  cout << "it = " << *it << " cit = " << *cit << endl; 

  //it = const_cast<vector<int>::iterator>(cit); 
  it = ivec.begin(); 
  std::advance(it, std::distance<vector<int>::const_iterator>(it, cit)); 
  cout << "it = " << *it << endl; 
  return 0; 
}

