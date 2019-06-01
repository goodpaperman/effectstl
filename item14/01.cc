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
  vector<int> ivec; 
  list<int> ilist; 
  set<int> iset; 
  map<int, int> imap; 

  cout << "ivec max: " << ivec.max_size() << endl; 
  cout << "ilist max: " << ilist.max_size() << endl; 
  cout << "iset max: " << iset.max_size() << endl; 
  cout << "imap max: " << imap.max_size() << endl; 

  ivec.reserve(ivec.max_size()/sizeof(int)); 
  cout << "ivec size: " << ivec.size() 
       << " ivec capacity: " << ivec.capacity() << endl; 
  return 0; 
}

