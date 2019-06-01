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
  srand(time(0)); 
  vector<int> ivec1, ivec2; 
  ivec1.reserve(20); 
  //ivec2.reserve(20); 
  for(int i=0; i<20; ++ i)
  {
    ivec1.push_back(i); 
    //ivec2.push_back(i); 
  }

  random_shuffle(ivec1.begin(), ivec1.end()); 
  //random_shuffle(ivec2.begin(), ivec2.end()); 

  cout << "after shuffle: " << endl; 
  copy(ivec1.begin(), ivec1.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 
  ivec2.assign(ivec1.begin(), ivec1.end());

  partial_sort(ivec1.begin(), ivec1.begin()+10, ivec1.end()); 
  nth_element(ivec2.begin(), ivec2.begin()+9, ivec2.end()); 
  
  cout << "after partial sort: " << endl; 
  copy(ivec1.begin(), ivec1.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 

  cout << "after nth element: " << endl; 
  copy(ivec2.begin(), ivec2.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl;  


  return 0; 
}

