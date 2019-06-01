#include <iostream>
#include <vector> 
#include <list> 
#include <deque>
#include <iterator> 
#include <algorithm> 
#include <sys/time.h> 
#include "../hrtime.h"

using std::ostream_iterator; 
using std::vector; 
using std::list;
using std::deque;  
using std::cout; 
using std::endl; 
using std::copy; 


int main()
{
  int old_capacity = 0, cnt = 0; 
  vector<int> ivec, ivec2; 
  for(int i=0; i<1000; ++ i)
  {
    ivec.push_back(i); 
    if(ivec.capacity() != old_capacity)
    {
      cout << "re-allocation: from " 
           << old_capacity << " to " 
           << ivec.capacity() << endl; 
      ++ cnt; 
      old_capacity = ivec.capacity(); 
    }
  }

  cout << "re_allocate " << cnt << " time(s)" << endl; 

  ivec2.push_back(2); 
  struct timeval tv1 = { 0 }, tv2 = { 0 }; 
  struct timezone tz = { 0 }; 
  gettimeofday(&tv1, &tz); 
  ivec2.assign(ivec.begin(), ivec.end()); 
  gettimeofday(&tv2, &tz); 
  //cout << "after assgin: " << endl; 
  //copy(ivec2.begin(), ivec2.end(), ostream_iterator<int>(cout, " ")); 
  
  cout << "assign " << ivec2.size() << " elapsed " 
       << tv2.tv_sec - tv1.tv_sec << "("
       << tv2.tv_usec - tv1.tv_usec << ")" << endl; 

  //ivec2.clear(); 
  //ivec2.swap((vector<int> ())); 
  vector<int>().swap(ivec2); 
  //ivec2.push_back(1); 
  gettimeofday(&tv1, &tz); 
  for(int i=0; i<1000; ++i)
    ivec2.push_back(i); 
  gettimeofday(&tv2, &tz); 
  
  cout << "push_back " << ivec2.size() << " elapsed " 
       << tv2.tv_sec - tv1.tv_sec << "("
       << tv2.tv_usec - tv1.tv_usec << ")" << endl; 

  //vector<int>().swap(ivec2); 
  gettimeofday(&tv1, &tz); 
  while(!ivec2.empty())
    ivec2.erase(ivec2.end()-1); 
  gettimeofday(&tv2, &tz); 

  cout << "erase " << ivec2.size() << " elapsed " 
       << tv2.tv_sec - tv1.tv_sec << "("
       << tv2.tv_usec - tv1.tv_usec << ")" << endl; 

  vector<int>().swap(ivec2); 
  //ivec2.push_back(3); 
  gettimeofday(&tv1, &tz); 
  copy(ivec.begin(), ivec.end(), back_inserter(ivec2)); 
  gettimeofday(&tv2, &tz); 

  cout << "copy " << ivec2.size() << " elpased " 
       << tv2.tv_sec - tv1.tv_sec << "(" 
       << tv2.tv_usec - tv1.tv_usec << ")" << endl; 

  gettimeofday(&tv1, &tz); 
  ivec2.erase(ivec2.begin(), ivec2.end()); 
  gettimeofday(&tv2, &tz); 

  cout << "erases " << ivec2.size() << " elapsed " 
       << tv2.tv_sec - tv1.tv_sec << "("
       << tv2.tv_usec - tv1.tv_usec << ")" << endl; 

  vector<int>().swap(ivec2); 
  //ivec2.push_back(4); 
  gettimeofday(&tv1, &tz); 
  ivec2.insert(ivec2.end(), ivec.begin(), ivec.end()); 
  gettimeofday(&tv2, &tz); 

  cout << "insert " << ivec2.size() << " elapsed " 
       << tv2.tv_sec - tv1.tv_sec << "("
       << tv2.tv_usec - tv1.tv_usec << ")" << endl; 

  gettimeofday(&tv1, &tz); 
  while(!ivec2.empty())
    ivec2.erase(ivec2.begin()); 
  gettimeofday(&tv2, &tz); 
  
  cout << "erase bkwd " << ivec2.size() << " elapsed " 
       << tv2.tv_sec - tv1.tv_sec << "(" 
       << tv2.tv_usec - tv1.tv_usec << ")" << endl; 
  
  
  vector<int>().swap(ivec2); 
  gettimeofday(&tv1, 0); 
  ivec2.insert(ivec2.begin(), ivec.begin(), ivec.end()); 
  gettimeofday(&tv2, 0); 

  cout << "insert front " << ivec2.size() << " elapsed " 
       << tv2.tv_sec - tv1.tv_sec << "("
       << tv2.tv_usec - tv1.tv_usec << ")" << endl; 


  vector<int>().swap(ivec2); 
  vector<int>::iterator it = ivec2.begin(); 
  gettimeofday(&tv1, 0); 
  for(int i=0; i<ivec.size(); ++ i)
  {
    it = ivec2.insert(it, ivec[i]); 
    ++ it; 
  }
  gettimeofday(&tv2, 0); 

  cout << "insert front " << ivec2.size() << " elapsed " 
       << tv2.tv_sec - tv1.tv_sec << "("
       << tv2.tv_usec - tv1.tv_usec << ")" << endl; 

  //cout << "after insertion: " << endl; 
  //copy(ivec2.begin(), ivec2.end(), ostream_iterator<int>(cout, " ")); 
  //cout << endl; 

  vector<int>().swap(ivec2); 
  gettimeofday(&tv1, 0); 
  copy(ivec.begin(), ivec.end(), inserter(ivec2, ivec2.begin())); 
  gettimeofday(&tv2, 0); 

  cout << "copy front " << ivec2.size() << " elapsed " 
       << tv2.tv_sec - tv1.tv_sec << "("
       << tv2.tv_usec - tv1.tv_usec << ")" << endl; 
  return 0; 
}

