#include <stdio.h>
#include <gem5/include/gem5/m5ops.h>

#define ASIZE 2048
#define STEP 128
#define ITERS 2000
#define LEN 2048

int arr[ASIZE];

struct ll {
  int val;
  int next_index;
};

__attribute__ ((noinline))
int loop(int zero, struct ll* nodes) {
  int t = 0, i, iter;
  for(iter = 0; iter < ITERS; ++iter) {
    int cur_index = 0;
    while(cur_index != -1) {
      t += nodes[cur_index].val;
      cur_index = nodes[cur_index].next_index;
    }
  }
  return t;
}

int main(int argc, char* argv[]) {
   argc &= 10000;
   struct ll nodes[LEN];

   int i;
   for(i = 0; i < LEN - 1; ++i) {
     nodes[i].val = i;
     nodes[i].next_index = i + 1;
   }
   nodes[LEN - 1].val = 100;
   nodes[LEN - 1].next_index = -1;

   m5_work_begin(0, 0); 
   int t = loop(argc, nodes);
   m5_work_end(0, 0);
   volatile int a = t;
}
