#include <iostream>
#include <fstream> 
#include <sstream> 
#include <vector> 
#include <list> 
#include <deque>
#include <set> 
#include <map> 
#include <string> 
#include <iterator> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <memory> 
#include <sys/time.h> 
#include "../hrtime.h"

using std::ostream_iterator; 
using std::ostreambuf_iterator; 
using std::istream_iterator; 
using std::istreambuf_iterator; 
using std::istringstream; 
using std::ostringstream; 
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
using std::ostream; 
using std::ofstream; 
using std::copy; 
using std::auto_ptr; 

struct point
{
  friend ostream& operator<< (ostream &os, const point &pt)
  {
    cout << "(" << pt.x_ << "," << pt.y_ << ")"; 
  }

  point(float x = 0.0, float y = 0.0) : x_(x), y_(y) { }
  float x_, y_; 
}; 

class point_avg : public std::unary_function<void, point>
{
public:
  point_avg() : num_(0), xsum_(0.0), ysum_(0.0) { }
  void operator() (const point &pt)
  {
    ++ num_; 
    xsum_ += pt.x_; 
    ysum_ += pt.y_; 
  }

  point result() const { return point(xsum_/num_, ysum_/num_); } 

private:
  int num_; 
  float xsum_, ysum_; 
}; 

int main()
{
  vector<point> ptvec; 
  ptvec.reserve(20); 
  for(int i=0; i<20; ++ i)
    ptvec.push_back(point(i, i)); 

  cout << "ptvec content: " << endl; 
  copy(ptvec.begin(), ptvec.end(), ostream_iterator<point>(cout, " ")); 
  cout << endl; 

  cout << "averge point: " << endl; 
  cout << for_each(ptvec.begin(), ptvec.end(), point_avg()).result() << endl; 

  return 0; 
}

