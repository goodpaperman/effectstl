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
using std::ifstream; 
using std::copy; 
using std::auto_ptr; 


int main()
{
  ifstream ifs("mass.txt"); 
  hrtime hrt; 
  hrt.start(); 
  string buffer((istream_iterator<char>(ifs)), 
                istream_iterator<char>()); 
  hrt.end(); 
  //cout << buffer << endl; 
  hrt.report(""); 
  cout << endl; 

  ifs.close(); 
  ifs.open("mass.txt"); 
  hrt.start(); 
  ifs.unsetf(std::ios::skipws); 
  string buffer2((istream_iterator<char>(ifs)), 
                  istream_iterator<char>()); 
  hrt.end(); 
  //cout << buffer2 << endl; 
  hrt.report(""); 
  cout << endl; 

  ifs.close(); 
  ifs.open("mass.txt"); 
  ifs.setf(std::ios::skipws); 
  hrt.start(); 
  string buffer3((istreambuf_iterator<char>(ifs)), 
                  istreambuf_iterator<char>()); 
  hrt.end(); 
  //cout << buffer3 << endl; 
  hrt.report(""); 
  cout << endl; 
  return 0; 
}

