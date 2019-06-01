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
  ivec.reserve(5); 
  for(int i=0; i<5; ++ i)
    ivec.push_back(i+1); 

  cout << "ivec content: " << endl; 
  copy(ivec.begin(), ivec.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 

  vector<int>::reverse_iterator ri = find(ivec.rbegin(), ivec.rend(), 3); 
  if(ri != ivec.rend())
  {
    cout << "find " << *ri << endl; 
    vector<int>::iterator it = ri.base(); 
    cout << "base() = " << *it << endl; 
    ivec.erase(--ri.base()); 
    cout << "after erase " << endl; 
    copy(ivec.begin(), ivec.end(), ostream_iterator<int>(cout, " ")); 
    cout << endl; 
  }
  return 0; 
}

