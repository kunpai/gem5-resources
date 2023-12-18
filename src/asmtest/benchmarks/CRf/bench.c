#include <stdio.h>
#include <gem5/include/gem5/m5ops.h>

#define ASIZE 2048
#define STEP   128
#define ITERS   32

__attribute__ ((noinline))
int fib(int i ){
  if(i==0) return 0;
  if(i==1) return 1;
  return fib(i-1) + fib(i-2);
}

__attribute__ ((noinline))
int loop(int zero) {
  int t = 0,i,iter;
  for(iter=0; iter < ITERS; ++iter) {
    t+=fib(iter);
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