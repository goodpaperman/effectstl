#include <iostream>
#include <vector> 
#include <list> 
#include <deque>
#include <set> 
#include <iterator> 
#include <algorithm> 
#include <sys/time.h> 
#include "../hrtime.h"

using std::ostream_iterator; 
using std::vector; 
using std::list;
using std::deque;  
using std::set; 
using std::cout; 
using std::endl; 
using std::copy; 


int main()
{
  set<int> iset, iset2; 
  for(int i=0; i<1000; ++ i)
    iset.insert(i); 

  hrtime hrt; 
  //iset2.insert(iset2.end(), 2); 
  //hrt.start(); 
  //iset2.assign(iset.begin(), iset.end()); 
  //hrt.end(); 
  //hrt.report("assign "); 
  //cout << "after assgin: " << endl; 
  //copy(iset2.begin(), iset2.end(), ostream_iterator<int>(cout, " ")); 
  
  //iset2.clear(); 
  //iset2.swap((set<int> ())); 
  set<int>().swap(iset2); 
  hrt.start(); 
  for(int i=0; i<1000; ++i)
    iset2.insert(i); 
  hrt.end(); 
  hrt.report("insert ");  

  set<int>().swap(iset2); 
  hrt.start(); 
  copy(iset.begin(), iset.end(), inserter(iset2, iset2.begin())); 
  hrt.end(); 
  hrt.report("copy "); 

  hrt.start();
  iset2.erase(iset2.begin(), iset2.end()); 
  hrt.end(); 
  hrt.report("erases "); 

  set<int>().swap(iset2); 
  hrt.start(); 
  iset2.insert(iset.begin(), iset.end()); 
  hrt.end(); 
  hrt.report("inserts "); 

  //set<int>().swap(iset2); 
  //hrt.start(); 
  //iset2.insert(iset.begin(), iset.end()); 
  //hrt.end(); 
  //hrt.report("inserts front"); 
  
  set<int>().swap(iset2); 
  set<int>::iterator it = iset2.begin(); 
  hrt.start(); 
  for(int i=0; i<1000; ++ i)
  {
    it = iset2.insert(it, i); 
    ++ it; 
  }
  hrt.end(); 
  hrt.report("insert front"); 

  //cout << "after insertion: " << endl; 
  //copy(iset2.begin(), iset2.end(), ostream_iterator<int>(cout, " ")); 
  //cout << endl; 

  set<int>().swap(iset2); 
  hrt.start(); 
  copy(iset.begin(), iset.end(), inserter(iset2, iset2.begin())); 
  hrt.end(); 
  hrt.report("copy front"); 
  return 0; 
}

