#include <iostream>
#include <vector> 
#include <list> 
#include <iterator> 
#include <algorithm> 
#include <sys/time.h> 

using std::ostream_iterator; 
using std::vector; 
using std::list; 
using std::cout; 
using std::endl; 
using std::copy; 


int main()
{
  list<int> ilist, ilist2; 
  for(int i=0; i<10000; ++ i)
  { 
    ilist.insert(ilist.begin(), i); 
    ilist2.insert(ilist2.begin(), i); 
  }

  cout << "list1: " << endl; 
  copy(ilist.begin(), ilist.end(), ostream_iterator<int>(cout, " ")); 

  cout << endl << "list2: " << endl; 
  copy(ilist2.begin(), ilist2.end(), ostream_iterator<int>(cout, " ")); 

  struct timeval tv1 = { 0 }, tv2 = { 0 }; 
  struct timezone tz = { 0 }; 
  gettimeofday(&tv1, &tz); 
  ilist.splice(ilist.end(), ilist2); //, ilist2.begin(), ilist2.end()); 
  gettimeofday(&tv2, &tz); 
  cout << endl << "after splice: " << endl; 
  copy(ilist.begin(), ilist.end(), ostream_iterator<int>(cout, " ")); 
  //gettimeofday(&tv2, &tz); 
 
  cout << endl << "elpased " 
       << tv2.tv_sec - tv1.tv_sec << "("
       << tv2.tv_usec - tv1.tv_usec << ")" << endl; 

  int sz = 0; 
  gettimeofday(&tv1, &tz); 
  sz = ilist.size(); 
  gettimeofday(&tv2, &tz); 
  cout << "list size = " << sz << " elapsed " 
       << tv2.tv_sec - tv1.tv_sec << "(" 
       << tv2.tv_usec - tv1.tv_usec << ")" << endl; 

  return 0; 
}

