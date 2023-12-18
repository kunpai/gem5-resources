#include <stdio.h>
#include "math.h"
#include <gem5/include/gem5/m5ops.h>

#define ASIZE   128
#define ITERS  3200

double arrA[ASIZE];
double arrB[ASIZE];

__attribute__ ((noinline))
double loop(int zero) {
  int i, iters;
  double t1;

  for(iters=zero; iters < ITERS; iters+=1) {
    for(i=zero; i < ASIZE; i+=1) {
      arrA[i]=sin(arrA[i]);
    }
    t1+=arrA[ASIZE-1];
  }

  return t1;
}

int main(int argc, char* argv[]) {
   argc&=10000;
   m5_work_begin(0, 0);
   int t=loop(argc); 
   m5_work_end(0, 0);
   volatile double a = t;
}