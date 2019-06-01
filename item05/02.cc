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
  list<int> ilist, ilist2; 
  for(int i=0; i<1000; ++ i)
    ilist.push_back(i); 

  hrtime hrt; 
  ilist2.insert(ilist2.end(), 2); 
  hrt.start(); 
  ilist2.assign(ilist.begin(), ilist.end()); 
  hrt.end(); 
  hrt.report("assign "); 
  //cout << "after assgin: " << endl; 
  //copy(ilist2.begin(), ilist2.end(), ostream_iterator<int>(cout, " ")); 
  
  //ilist2.clear(); 
  //ilist2.swap((list<int> ())); 
  list<int>().swap(ilist2); 
  hrt.start(); 
  for(int i=0; i<1000; ++i)
    ilist2.insert(ilist2.end(), i); 
  hrt.end(); 
  hrt.report("insert ");  

  ////list<int>().swap(ilist2); 
  //hrt.start(); 
  //while(!ilist2.empty())
  //  ilist2.erase(ilist2.front()); 
  //hrt.end(); 
  //hrt.report("erase "); 

  list<int>().swap(ilist2); 
  hrt.start(); 
  copy(ilist.begin(), ilist.end(), back_inserter(ilist2)); 
  hrt.end(); 
  hrt.report("copy "); 

  hrt.start();
  ilist2.erase(ilist2.begin(), ilist2.end()); 
  hrt.end(); 
  hrt.report("erases "); 

  list<int>().swap(ilist2); 
  hrt.start(); 
  ilist2.insert(ilist2.end(), ilist.begin(), ilist.end()); 
  hrt.end(); 
  hrt.report("inserts "); 

  //hrt.start(); 
  //while(!ilist2.empty())
  //  ilist2.erase(ilist2.begin()); 
  //hrt.end(); 
  //hrt.report("erase backward ");  
  
  list<int>().swap(ilist2); 
  hrt.start(); 
  ilist2.insert(ilist2.begin(), ilist.begin(), ilist.end()); 
  hrt.end(); 
  hrt.report("inserts front"); 
  
  list<int>().swap(ilist2); 
  list<int>::iterator it = ilist2.begin(); 
  hrt.start(); 
  for(int i=0; i<1000; ++ i)
  {
    it = ilist2.insert(it, i); 
    ++ it; 
  }
  hrt.end(); 
  hrt.report("insert front"); 

  //cout << "after insertion: " << endl; 
  //copy(ilist2.begin(), ilist2.end(), ostream_iterator<int>(cout, " ")); 
  //cout << endl; 

  list<int>().swap(ilist2); 
  hrt.start(); 
  copy(ilist.begin(), ilist.end(), inserter(ilist2, ilist2.begin())); 
  hrt.end(); 
  hrt.report("copy front"); 
  return 0; 
}

