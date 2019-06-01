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

int key_from_pair(const std::pair<int, int> &intpair)
{
  return intpair.first; 
}

int main()
{
  set<int> iset; 
  map<int, int> imap; 
  for(int i=0; i<10; ++ i)
  {
    iset.insert(i); 
    imap.insert(std::make_pair(i, i)); 
  }

  cout << "iset content: " << endl; 
  copy(iset.begin(), iset.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 

  cout << "imap content: " << endl; 
  transform(imap.begin(), imap.end(), 
            ostream_iterator<int>(cout, " "), 
            key_from_pair); 
  cout << endl; 

  set<int>::iterator sit = iset.find(5); 
  if(sit != iset.end())
    const_cast<int&>(*sit) = 100; 

  cout << "after alter set content: " << endl; 
  copy(iset.begin(), iset.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 
  
  map<int, int>::iterator mit = imap.find(5); 
  if(mit != imap.end())
    const_cast<int&>(mit->first) = 100; 

  cout << "after alter map content: " << endl; 
  transform(imap.begin(), imap.end(), 
            ostream_iterator<int>(cout, " "), 
            key_from_pair); 
  cout << endl; 
  return 0; 
}

