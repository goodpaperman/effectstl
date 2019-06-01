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


int main()
{
  string buffer;
  buffer.reserve(4096); 
  for(int i=0; i<4096; ++ i)
    buffer.push_back(i % 26 + 'A'); 

  hrtime hrt; 
  hrt.start(); 
  copy(buffer.begin(), buffer.end(), ostream_iterator<char>(cout, "")); 
  cout << endl; 
  hrt.end(); 
  hrt.report(""); 
  cout << endl; 

  hrt.start(); 
  cout.unsetf(std::ios::skipws); 
  copy(buffer.begin(), buffer.end(), ostream_iterator<char>(cout, "")); 
  cout << endl; 
  hrt.end(); 
  hrt.report(""); 
  cout << endl; 

  cout.setf(std::ios::skipws); 
  hrt.start(); 
  copy(buffer.begin(), buffer.end(), ostreambuf_iterator<char>(cout)); 
  hrt.end(); 
  hrt.report(""); 
  cout << endl; 
  return 0; 
}

