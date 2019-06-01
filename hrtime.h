#include <sys/time.h> 
#include <iostream> 
using std::cout; 
using std::endl; 

class hrtime
{
public: 
  hrtime() : tv1_(), tv2_() {}
  void start() { gettimeofday(&tv1_, 0); } 
  void end(){ gettimeofday(&tv2_, 0); }
  double elapse() { 
    return 1.0 * (tv2_.tv_sec - tv1_.tv_sec) + 
           0.000001 * (tv2_.tv_usec - tv1_.tv_usec); }

  void report(const char *heading) {
    cout << heading << " elapsed " 
         << 1000000.0 * (tv2_.tv_sec - tv1_.tv_sec) + 
            (tv2_.tv_usec - tv1_.tv_usec) << endl; }

private:
  struct timeval tv1_, tv2_; 
}; 
