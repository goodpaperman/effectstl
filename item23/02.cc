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

typedef std::pair<int, int> pair_t; 
class pair_compare
{
public:
  bool operator() (const pair_t &lhs, const pair_t &rhs) const
  { return key_compare(lhs.first, rhs.first); } 

  bool operator() (const pair_t &lhs, int rhs) const 
  { return key_compare(lhs.first, rhs); } 

  bool operator() (int lhs, const pair_t &rhs) const
  { return key_compare(lhs, rhs.first); } 

private:
  bool key_compare(int lhs, int rhs) const 
  { return lhs < rhs; } 
}; 

int main()
{
  map<int, int> imap; 
  vector<std::pair<int, int> > ivec; 
  ivec.reserve(1000000); 
  for(int i=0; i<1000000; ++ i)
  {
    ivec.push_back(std::make_pair(i, i)); 
    imap.insert(std::make_pair(i, i)); 
  }

  int target = 0; 
  hrtime hrt; 
  sort(ivec.begin(), ivec.end(), pair_compare()); 

  target = 1; 
  hrt.start(); 
  map<int, int>::iterator sit = imap.find(target); 
  hrt.end(); 
  if(sit != imap.end())
  {
    cout << "find " << target << " in map" << endl; 
    hrt.report(""); 
  }
 
  hrt.start();  
  vector<std::pair<int, int> >::iterator vit = 
        std::lower_bound(ivec.begin(), ivec.end(), target, pair_compare()); 
  hrt.end(); 
  if(vit != ivec.end() && !pair_compare()(target, *vit))
  {
    cout << "find " << target << " in vec" << endl; 
    hrt.report(""); 
  }

  return 0; 
}

