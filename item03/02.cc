#include <iostream>
#include <vector> 
#include <iterator> 
#include <algorithm> 

using std::ostream_iterator; 
using std::vector; 
using std::cout; 
using std::endl; 
using std::copy; 

class Widget
{
public:
  Widget() : id_(0) {}
  Widget(int i) : id_(i) {}
  Widget(const Widget &rhs) : id_(rhs.id_) { cout << "copy ctor." << endl; }
  const Widget& operator= (const Widget &rhs) { 
    id_ = rhs.id_; 
    cout << "assign ctor." << endl; 
  }

  operator int() const { return id_; } 
  bool operator< (const Widget &rhs) const { return id_ < rhs.id_; }   

private:
  int id_; 
}; 

int main()
{
  int iarr[] = { 1, 4, 4, 3, 5, 2, 4, 6 }; 

  vector<Widget> wvec(iarr, iarr + 8);   
  cout << "original: " << endl; 
  copy(wvec.begin(), wvec.end(), ostream_iterator<int>(cout, " ")); 

  //std::unique(wvec.begin(), wvec.end()); 
  //cout << endl << "after unique: " << endl; 
  //copy(wvec.begin(), wvec.end(), ostream_iterator<int>(cout, " ")); 

  std::sort(wvec.begin(), wvec.end()); 
  cout << endl << "after sort: " << endl; 
  copy(wvec.begin(), wvec.end(), ostream_iterator<int>(cout, " ")); 

  //std::remove(wvec.begin(), wvec.end(), 3); 
  wvec.erase(std::remove(wvec.begin(), wvec.end(), 3), wvec.end()); 
  cout << endl << "after remove: " << endl; 
  copy(wvec.begin(), wvec.end(), ostream_iterator<int>(cout, " "));

  //std::unique(wvec.begin(), wvec.end()); 
  wvec.erase(std::unique(wvec.begin(), wvec.end()), wvec.end()); 
  cout << endl << "after unique: " << endl; 
  copy(wvec.begin(), wvec.end(), ostream_iterator<int>(cout, " "));   

  //for(int i=0; i<100; ++ i)
  //{
  std::next_permutation(wvec.begin(), wvec.end());  
  cout << endl << "after next_permutation: " << endl;  
  copy(wvec.begin(), wvec.end(), ostream_iterator<int>(cout, " ")); 
  //}

  std::prev_permutation(wvec.begin(), wvec.end());
  cout << endl << "after prev_permutation: " << endl; 
  copy(wvec.begin(), wvec.end(), ostream_iterator<int>(cout, " "));

  std::rotate(wvec.begin(), wvec.begin()+wvec.size()/2, wvec.end()); 
  cout << endl << "after rotate: " << endl;  
  copy(wvec.begin(), wvec.end(), ostream_iterator<int>(cout, " ")); 

  std::reverse(wvec.begin(), wvec.end()); 
  cout << endl << "after reverse: " << endl; 
  copy(wvec.begin(), wvec.end(), ostream_iterator<int>(cout, " ")); 

  cout << endl; 
  return 0; 
}

