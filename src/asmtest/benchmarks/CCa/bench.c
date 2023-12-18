#include <stdio.h>
#include <gem5/include/gem5/m5ops.h>

#define ASIZE 512
#define STEP  512
#define ITERS 512

__attribute__ ((noinline))
int loop(int zero) {
  int t = 0,i,iter;
  for(iter=0; iter < ITERS; ++iter) {
    for(i=zero; i < STEP; i+=1) {
      if(i<zero)  {
        t+=3+3*t;
      } else {
        t-=1-5*t;
      }
    }
  }
  return t;
}

int main(int argc, char* argv[]) {
   argc&=10000;
    m5_work_begin(0, 0);
   int t=loop(argc);
    m5_work_end(0, 0);
   volatile int a = t;
}