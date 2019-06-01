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
using std::multimap; 
using std::map;  
using std::string; 
using std::cin; 
using std::cout; 
using std::endl; 
using std::ifstream; 
using std::copy; 
using std::auto_ptr; 


int main()
{
  vector<int> ivec; 
  ivec.reserve(10); 
  for(int i=0; i<10; ++ i)
    ivec.push_back(i); 

  vector<int>::iterator nit = find(ivec.begin(), ivec.end(), 5); 
  if(nit != ivec.end())
    cout << "find 5 @ " << *nit << endl; 

  vector<int>::const_iterator cit = nit; 
  cout << "const iterator = " << *cit << endl; 

  //nit = cit; 
  
  //vector<int>::reverse_iterator rit = nit; 
  vector<int>::reverse_iterator rit = find(ivec.rbegin(), ivec.rend(), 5); 
  if(rit != ivec.rend())
    cout << "reverse iterator = " << *rit << endl; 

  vector<int>::const_reverse_iterator crit = rit; 
  cout << "const reverse iterator = " << *crit << endl; 

  //rit = crit; 
  //nit = rit; 
  //rit = nit; 
  nit = rit.base(); 
  cout << "reverse iterator base = " << *nit << endl; 

  //rit = nit.base(); 
  cit = crit.base(); 
  cout << "const reverse iterator base = " << *cit << endl; 

  cout << "const it == it ? " << (cit == nit) << endl; 
  cout << "const reverse it = reverse it ? " << (crit == rit) << endl; 
  //nit == rit; 
  cout << "it == reverse it base ? " << (nit == rit.base()) << endl; 

  return 0; 
}

