#include <stdio.h>
#include <gem5/include/gem5/m5ops.h>

#define ASIZE 2048
#define STEP   128
#define ITERS 2000000

__attribute__ ((noinline))
int loop(int zero) {
  int t1 = zero*zero+zero+1;

  int i;
  for(i=zero; i < ITERS; i+=1) {
    t1=t1/(zero+1);
  }
  return t1;
}

int main(int argc, char* argv[]) {
   argc&=10000;
   m5_work_begin(0, 0);
   int t=loop(argc); 
   m5_work_end(0, 0);
   volatile int a = t;
}