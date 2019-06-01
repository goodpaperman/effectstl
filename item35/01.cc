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

int char_nocase_compare(char c1, char c2)
{
  int lc1 = tolower(c1); 
  int lc2 = tolower(c2); 
  if(lc1 < lc2) return -1; 
  else if(lc2 < lc1) return 1; 
  else return 0; 
}

int string_nocase_compare_imp(const string &s1, const string &s2)
{
  std::pair<string::const_iterator, string::const_iterator> ret = 
    std::mismatch(s1.begin(), s1.end(), s2.begin(), 
                  std::not2(std::ptr_fun(char_nocase_compare))); 

  if(ret.first == s1.end())
  {
    if(ret.second == s2.end()) return 0; 
    else return -1; 
  }

  return char_nocase_compare(*ret.first, *ret.second); 
}

int string_nocase_compare(const string &s1, const string &s2)
{
  if(s1.size() <= s2.size())
    return string_nocase_compare_imp(s1, s2); 
  else 
    return -string_nocase_compare_imp(s2, s1); 
}

int main()
{
  string s1("hello World!"); 
  string s2("Hello world!"); 
  cout << "s1 == s2 ? " << string_nocase_compare(s1, s2) << endl; 

  s1 = "hello"; 
  s2 = "hello world"; 
  cout << "s1 == s2 ? " << string_nocase_compare(s1, s2) << endl; 

  s2 = "hello"; 
  s1 = "world"; 
  cout << "s1 == s2 ? " << string_nocase_compare(s1, s2) << endl; 

  return 0; 
}

