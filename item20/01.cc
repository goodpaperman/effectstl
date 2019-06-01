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


void print(const char *sz)
{
  cout << sz << endl; 
}

int main()
{
  set<char*> szset; 
  szset.insert("Anteater"); 
  szset.insert("Wombat"); 
  szset.insert("Lemur"); 
  szset.insert("Penguin"); 

  for_each(szset.begin(), szset.end(), print);   

  return 0; 
}

