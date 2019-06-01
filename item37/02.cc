#include <iostream>
#include <fstream> 
#include <sstream> 
#include <vector> 
#include <list> 
#include <deque>
#include <set> 
#include <map> 
#include <string> 
#include <iterator> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <memory> 
#include <sys/time.h> 
#include "../hrtime.h"

using std::ostream_iterator; 
using std::ostreambuf_iterator; 
using std::istream_iterator; 
using std::istreambuf_iterator; 
using std::istringstream; 
using std::ostringstream; 
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

string::size_type string_total_length(string::size_type sum, const string &s)
{
  return sum + s.length(); 
}

int main()
{
  vector<string> svec; 
  svec.reserve(20); 
  for(int i=0; i<20; ++ i)
  {
    ostringstream oss; 
    oss << i; 
    svec.push_back(oss.str()); 
  }

  cout << "string vector content: " << endl; 
  copy(svec.begin(), svec.end(), ostream_iterator<string>(cout, " ")); 
  cout << endl; 

  cout << "accumulate string length is: "; 
  cout << accumulate(svec.begin(), svec.end(), 0, string_total_length) << endl; 
  return 0; 
}

