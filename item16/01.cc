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
using std::cout; 
using std::endl; 
using std::ifstream; 
using std::copy; 
using std::auto_ptr; 


void process_ints(int *iarr, int size)
{
  for(int i=0; i<size; ++ i)
    iarr[i] = i * 2 + 1; 
}

void print_ints(int *iarr, int size)
{
  for(int i=0; i<size; ++ i)
    cout << iarr[i] << " "; 
}

int main()
{
  vector<int> ivec(100); 
  process_ints(&ivec[0], ivec.size()); 
  cout << "after process: " << endl; 
  copy(ivec.begin(), ivec.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 

  vector<int> ivec2; 
  ivec2.reserve(100); 
  for(int i=0; i<100; ++ i)
    ivec2.push_back(i*2-1); 

  print_ints(&ivec2[0], ivec2.size()); 
  cout << endl; 
  return 0; 
}

