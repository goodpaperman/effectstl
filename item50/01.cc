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
#include <ext/functional> 
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
using std::ostream; 
using std::ofstream; 
using std::copy; 
using std::auto_ptr; 


int main()
{
  map<int, string> ismap; 
  for(int i=0; i<20; ++ i)
  {
    ostringstream oss; 
    oss << "string" << i; 
    ismap.insert(std::make_pair(i, oss.str())); 
  }

  cout << "keys in map: " << endl; 
  transform(ismap.begin(), ismap.end(), 
            ostream_iterator<int>(cout, " "), 
            __gnu_cxx::select1st<map<int, string>::value_type>()); 

  cout << endl; 
  cout << "values in map: " << endl; 
  transform(ismap.begin(), ismap.end(), 
            ostream_iterator<string>(cout, " "), 
            __gnu_cxx::select2nd<map<int, string>::value_type>()); 
  cout << endl; 
  return 0; 
}

