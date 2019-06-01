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

int transmogrify(int x)
{
  return x & (x - 1); 
}

int main()
{
  vector<int> ivec; 
  ivec.reserve(32); 
  for(int i=0; i<20; ++ i)
    ivec.push_back(i); 

  cout << "ivec content: " << endl; 
  copy(ivec.begin(), ivec.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 

  vector<int> result; 
  //transform(ivec.begin(), ivec.end(), result.begin(), transmogrify); 
  transform(ivec.begin(), ivec.end(), back_inserter(result), transmogrify); 
  cout << "after transform: " << endl; 
  copy(result.begin(), result.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 

  list<int> ilist; 
  transform(result.begin(), result.end(), front_inserter(ilist), transmogrify); 
  cout << "after transform: " << endl; 
  copy(ilist.begin(), ilist.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 

  list<int>().swap(ilist); 
  transform(result.rbegin(), result.rend(), front_inserter(ilist), transmogrify);
  cout << "after transform: " << endl; 
  copy(ilist.begin(), ilist.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 

  cout << "size = " << ivec.size() << " capacity = " << ivec.capacity() << endl; 
  vector<int>(ivec).swap(ivec); 
  cout << "size = " << ivec.size() << " capacity = " << ivec.capacity() << endl;
 
  result.reserve(result.size() + ivec.size()); 
  transform(ivec.begin(), ivec.end(), 
            inserter(result, result.begin() + result.size()/2), 
            transmogrify); 

  cout << "after transform: " << endl; 
  copy(result.begin(), result.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 
 
  result.resize(ivec.size()); 
  transform(ivec.begin(), ivec.end(), result.begin(), transmogrify); 
  cout << "after transform:" << endl; 
  copy(result.begin(), result.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 
 
  return 0; 
}

