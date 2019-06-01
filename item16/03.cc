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



int main()
{
  //vector<char> cvec((istream_iterator<char> (cin)), 
  //                  istream_iterator<char> ()); 
  //string str(cvec.begin(), cvec.end()); 
  //cout << "your input is: " << endl; 
  //cout << str << endl; 

  string str2((istream_iterator<char> (cin)), 
              istream_iterator<char> ()); 
  cout << str2 << endl; 
  return 0; 
}

