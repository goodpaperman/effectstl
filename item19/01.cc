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

struct str_case_i_comp : public std::binary_function<string, string, bool> 
{
  bool operator() (const string &lhs, const string &rhs) const
  {  return strcasecmp(lhs.c_str(), rhs.c_str()); } 
}; 


int main()
{
  set<string, str_case_i_comp> strset; 
  strset.insert("Persephone"); 
  strset.insert("persephone"); 
  copy(strset.begin(), strset.end(), ostream_iterator<string>(cout, " ")); 
  cout << endl; 

  set<string>::iterator it = strset.find("persephone"); 
  if(it != strset.end())
  {
    cout << "find persephone" << endl; 
    cout << *it << endl; 
  }

  it = find(strset.begin(), strset.end(), "persephone"); 
  if(it == strset.end())
    cout << "not find persephone." << endl; 
  return 0; 
}

