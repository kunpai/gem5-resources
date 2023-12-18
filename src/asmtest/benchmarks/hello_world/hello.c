#include <stdio.h>
#include <stdlib.h>
#include <gem5/include/gem5/m5ops.h>

int main(int argc, char** argv) {
    m5_work_begin(0, 0);
    printf("Hello, world!\n");
    m5_work_end(0, 0);
  return 0;
}