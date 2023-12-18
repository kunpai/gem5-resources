#include <stdio.h>
#include <gem5/include/gem5/m5ops.h>

#define ASIZE 2048
#define STEP  1024
#define ITERS 1600

int arr[ASIZE];

__attribute__ ((noinline))
int loop(int zero) {
  int t = 0,i,iter;
  for(iter=0; iter < ITERS; ++iter) {
    for(i=zero; i < STEP; ++i) {
      arr[i]=i; 
    }
    t+=arr[ASIZE-1-zero];
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