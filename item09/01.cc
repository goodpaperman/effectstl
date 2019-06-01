#include <iostream>
#include <fstream> 
#include <vector> 
#include <list> 
#include <deque>
#include <set> 
#include <string> 
#include <iterator> 
#include <algorithm> 
#include <functional> 
#include <sys/time.h> 
#include "../hrtime.h"

using std::ostream_iterator; 
using std::istream_iterator; 
using std::vector; 
using std::list;
using std::deque;  
using std::set; 
using std::string; 
using std::cout; 
using std::endl; 
using std::ifstream; 
using std::copy; 
using std::auto_ptr; 

bool is_bad_val(int v)
{
  return v % 2 == 0; 
}

int main()
{
  srand(time(0)); 
  vector<int> ivec; 
  list<int> ilist; 
  set<int> iset; 

  const int max = 20; 
  int target = 0; 
  ivec.reserve(max); 
  for(int i=0; i<max; ++ i)
  {
    target = rand() % max; 
    ivec.push_back(target); 
    ilist.push_back(target); 
    iset.insert(target); 
  }

  sort(ivec.begin(), ivec.end()); 
  cout << "ivec content: " << ivec.size() << endl; 
  copy(ivec.begin(), ivec.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 

  ilist.sort(); 
  //sort(ilist.begin(), ilist.end()); 
  cout << "ilist content: " << ilist.size() << endl; 
  copy(ilist.begin(), ilist.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 

  cout << "iset content: " << iset.size() << endl; 
  copy(iset.begin(), iset.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 

  target = ivec[rand() % max]; 
  ivec.erase(remove(ivec.begin(), ivec.end(), target), ivec.end()); 
  ilist.remove(target); 
  iset.erase(target); 

  cout << endl; 
  cout << "after remove " << target << endl; 
  cout << "ivec content: " << ivec.size() << endl; 
  copy(ivec.begin(), ivec.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 

  cout << "ilist content: " << ilist.size() << endl; 
  copy(ilist.begin(), ilist.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 

  cout << "iset content: " << iset.size() << endl; 
  copy(iset.begin(), iset.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 

  ivec.erase(remove_if(ivec.begin(), ivec.end(), is_bad_val), ivec.end()); 
  ilist.remove_if(is_bad_val); 
  set<int> tmp; 
  remove_copy_if(iset.begin(), iset.end(), 
                 inserter(tmp, tmp.end()), is_bad_val); 
  iset.swap(tmp); 
  //for(set<int>::iterator it = iset.begin(); it != iset.end();)
  //{
  //  if(is_bad_val(*it))
  //    iset.erase(it++); 
  //  else 
  //    ++ it; 
  //}
  
  cout << endl; 
  cout << "after remove bad values " << endl; 
  cout << "ivec content: " << ivec.size() << endl; 
  copy(ivec.begin(), ivec.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 

  cout << "ilist content: " << ilist.size() << endl; 
  copy(ilist.begin(), ilist.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 

  cout << "iset content: " << iset.size() << endl; 
  copy(iset.begin(), iset.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl; 

  return 0; 
}

