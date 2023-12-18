#include <stdio.h>
#include <gem5/include/gem5/m5ops.h>

#define ASIZE 131072
#define STEP     512
#define ITERS    256

int arr[ASIZE];

__attribute__ ((noinline))
int loop(int zero) {
  int t = 0,i,iter;
  for(iter=0; iter < ITERS; ++iter) {
    for(i=iter; i < ASIZE; i+=STEP) {
      arr[i]=i;
    }
    t+=arr[zero];
  }
  return t+arr[zero];
}

int main(int argc, char* argv[]) {
   argc&=10000;
   m5_work_begin(0,0);
   int t=loop(argc); 
   m5_work_end(0,0);
   volatile int a = t;
}