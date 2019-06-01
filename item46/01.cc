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
using std::ostream; 
using std::ofstream; 
using std::copy; 
using std::auto_ptr; 

bool is_greater(int lhs, int rhs)
{
  return lhs > rhs; 
}

int is_greater_ex(const void *lhs, const void *rhs)
{
  return *(int*)rhs - *(int*)lhs; 
}

int main()
{
  vector<int> ivec; 
  ivec.reserve(1000000); 
  for(int i=0; i<1000000; ++ i)
    ivec.push_back(i); 

  hrtime hrt; 
  hrt.start(); 
  sort(ivec.begin(), ivec.end(), std::greater<int>()); 
  hrt.end(); 
  hrt.report("std::greater<int>"); 
  cout << "after sort: " << endl; 
  copy(ivec.begin(), ivec.begin()+20, ostream_iterator<int>(cout, " ")); 
  cout << endl; 

  reverse(ivec.begin(), ivec.end()); 
  hrt.start(); 
  sort(ivec.begin(), ivec.end(), is_greater); 
  hrt.end(); 
  hrt.report("is_greater"); 
  cout << "after sort: " << endl; 
  copy(ivec.begin(), ivec.begin()+20, ostream_iterator<int>(cout, " ")); 
  cout << endl; 

  reverse(ivec.begin(), ivec.end()); 
  hrt.start(); 
  qsort(&ivec[0], ivec.size(), sizeof(int), is_greater_ex); 
  hrt.end(); 
  hrt.report("qsort"); 
  cout << "after sort: " << endl; 
  copy(ivec.begin(), ivec.begin()+20, ostream_iterator<int>(cout, " ")); 
  cout << endl; 

  return 0; 
}

