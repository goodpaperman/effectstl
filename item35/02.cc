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

bool char_nocase_less(char c1, char c2)
{
  return tolower(c1) < tolower(c2); 
}

class string_nocase_compare : 
             public std::binary_function<string&, string&, bool>
{
public:
  bool operator()(const string &s1, const string &s2)
  {
    return lexicographical_compare(s1.begin(), s1.end(), 
                                   s2.begin(), s2.end(), 
                                   char_nocase_less); 
  }
}; 

int main()
{
  set<string, string_nocase_compare> sset; 
  sset.insert("hello World!"); 
  sset.insert("Hello world!"); 
  sset.insert("hello"); 
  sset.insert("hello world"); 
  sset.insert("world"); 

  cout << "set content: " << endl; 
  copy(sset.begin(), sset.end(), ostream_iterator<string>(cout, "\n")); 
  cout << endl; 
  return 0; 
}

