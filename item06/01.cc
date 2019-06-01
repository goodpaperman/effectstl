#include <iostream>
#include <fstream> 
#include <vector> 
#include <list> 
#include <deque>
#include <set> 
#include <string> 
#include <iterator> 
#include <algorithm> 
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


int main()
{
  const char *filename = "../hrtime.h"; 
  ifstream ifs(filename); 
  istream_iterator<string> beg(ifs), end; 
  //vector<string> dictionary(beg, end); 
  vector<string> dictionary((istream_iterator<string> (ifs)), 
                            istream_iterator<string> ()); 

  cout << "after read " << dictionary.size() << endl; 
  copy(dictionary.begin(), dictionary.end(), 
       ostream_iterator<string>(cout, " ")); 

  return 0; 
}

