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
using std::multiset; 
using std::map;  
using std::string; 
using std::cin; 
using std::cout; 
using std::endl; 
using std::ifstream; 
using std::copy; 
using std::auto_ptr; 

class widget
{
public:
  widget() : id_(0), title_() {}
  widget(int id) : id_(id), title_() { sprintf(title_, "%d", id); }
  bool operator< (const widget &rhs) const { return id_ < rhs.id_; } 

  int id() const { return id_; } 
  void id(int id) { id_ = id; } 
  const char* title() const { return title_; } 
  void title(const char *title) { strcpy(title_, title); } 

private:
  int id_; 
  char title_[20]; 
};

void print(const widget &w)
{
  cout << w.id() << " " << w.title() << endl; 
}

void print2(std::pair<const widget, int> &w)
{
  cout << w.first.id() << " " 
       << w.first.title() << " " 
       << w.second << endl;
}

int main()
{
  set<widget> iset; 
  map<widget, int> imap; 
  for(int i=0; i<10; ++ i)
  {
    iset.insert(i); 
    imap.insert(std::make_pair(widget(i), i)); 
  }

  cout << "iset content: " << endl; 
  for_each(iset.begin(), iset.end(), print); 
  cout << endl; 

  cout << "imap content: " << endl; 
  for_each(imap.begin(), imap.end(), print2); 
  cout << endl; 

  set<widget>::iterator sit = iset.find(5); 
  if(sit != iset.end())
  {
    //const_cast<widget&>(*sit).title("hello world"); 
    widget tmp(sit->id()); 
    iset.erase(sit++); 
    //tmp.id(42); 
    //tmp.id(4); 
    tmp.title("hello world"); 
    iset.insert(sit, tmp); 
  }

  cout << "after alter set content: " << endl; 
  for_each(iset.begin(), iset.end(), print); 
  cout << endl; 
  
  map<widget, int>::iterator mit = imap.find(5); 
  if(mit != imap.end())
  {
    //const_cast<widget&>(mit->first).title("persephone"); 
    widget tmp(mit->first.id()); 
    imap.erase(mit++); 
    //tmp.id(42); 
    //tmp.id(4); 
    tmp.title("persephone");
    imap.insert(mit, std::make_pair(tmp, tmp.id())); 
  }

  cout << "after alter map content: " << endl; 
  for_each(imap.begin(), imap.end(), print2); 
  cout << endl; 
  return 0; 
}

