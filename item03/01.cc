#include <iostream>
#include <vector> 
#include <iterator> 
#include <algorithm> 

using std::ostream_iterator; 
using std::vector; 
using std::cout; 
using std::endl; 
using std::copy; 

int main()
{
  int iarr[] = { 1, 4, 4, 3, 5, 2, 4, 6 }; 

  vector<int> ivec(iarr, iarr + 8);   
  cout << "original: " << endl; 
  copy(ivec.begin(), ivec.end(), ostream_iterator<int>(cout, " ")); 

  //std::unique(ivec.begin(), ivec.end()); 
  //cout << endl << "after unique: " << endl; 
  //copy(ivec.begin(), ivec.end(), ostream_iterator<int>(cout, " ")); 

  std::sort(ivec.begin(), ivec.end()); 
  cout << endl << "after sort: " << endl; 
  copy(ivec.begin(), ivec.end(), ostream_iterator<int>(cout, " ")); 

  //std::remove(ivec.begin(), ivec.end(), 3); 
  ivec.erase(std::remove(ivec.begin(), ivec.end(), 3), ivec.end()); 
  cout << endl << "after remove: " << endl; 
  copy(ivec.begin(), ivec.end(), ostream_iterator<int>(cout, " "));

  //std::unique(ivec.begin(), ivec.end()); 
  ivec.erase(std::unique(ivec.begin(), ivec.end()), ivec.end()); 
  cout << endl << "after unique: " << endl; 
  copy(ivec.begin(), ivec.end(), ostream_iterator<int>(cout, " "));   

  //for(int i=0; i<100; ++ i)
  //{
  std::next_permutation(ivec.begin(), ivec.end());  
  cout << endl << "after next_permutation: " << endl;  
  copy(ivec.begin(), ivec.end(), ostream_iterator<int>(cout, " ")); 
  //}

  std::prev_permutation(ivec.begin(), ivec.end());
  cout << endl << "after prev_permutation: " << endl; 
  copy(ivec.begin(), ivec.end(), ostream_iterator<int>(cout, " "));

  std::rotate(ivec.begin(), ivec.begin()+ivec.size()/2, ivec.end()); 
  cout << endl << "after rotate: " << endl;  
  copy(ivec.begin(), ivec.end(), ostream_iterator<int>(cout, " ")); 

  std::reverse(ivec.begin(), ivec.end()); 
  cout << endl << "after reverse: " << endl; 
  copy(ivec.begin(), ivec.end(), ostream_iterator<int>(cout, " ")); 

  cout << endl; 
  return 0; 
}

