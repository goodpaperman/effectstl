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
#include <numeric> 
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
  vector<double> dvec; 
  dvec.reserve(20); 
  for(int i=0; i<20; ++ i)
    dvec.push_back(1.0 * (i & (i+5) | 0x01) / (i+1)); 

  cout << "dvec content: " << endl; 
  copy(dvec.begin(), dvec.end(), ostream_iterator<double>(cout, " ")); 
  cout << endl; 

  double ret = std::accumulate(dvec.begin(), dvec.end(), 0.0); 
  cout << "accumulate of double = " << ret << endl; 
  ret = std::accumulate(dvec.begin(), dvec.end(), 0); 
  cout << "accumulate of int = " << ret << endl; 

  ret = std::accumulate(dvec.begin(),dvec.end(),1.0f,std::multiplies<float>()); 
  cout << "accumulate of float = " << ret << endl; 

  cout << "accumulate of standard input is: "
       << accumulate(istream_iterator<double>(cin), 
                     istream_iterator<double>(), 0.0) 
       << endl; 
  return 0; 
}

