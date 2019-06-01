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
using std::multiset; 
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
  set<int, std::less_equal<int> > iset; 
  for(int i=0; i<10; ++ i)
    iset.insert(42); 

  cout << "set content: " << endl; 
  copy(iset.begin(), iset.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 

  multiset<int> imset; 
  for(int i=0; i<10; ++ i)
    imset.insert(42); 

  cout << "mutliset content: " << endl; 
  copy(imset.begin(), imset.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 

  std::pair<multiset<int>::iterator, multiset<int>::iterator> ret = 
       equal_range(imset.begin(), imset.end(), 42); 

  cout << "equal_range: " << endl; 
  copy(ret.first, ret.second, ostream_iterator<int>(cout, " ")); 
  cout << endl; 

  return 0; 
}

