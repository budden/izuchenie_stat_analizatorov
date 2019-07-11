#include <stdio.h>
#include <stdlib.h>
#include "../leontqev1.h"

void work_with_file(int condition) {
  FILE *fp;
  int flag;
  if (condition) {
    fp = fopen("example.txt", "r");
    flag = 1;
  } else {
    flag = 0;
  }
  if (flag) {
    fclose(fp);
  }
}

void test_ps_no_errors1_c() {
  int v1 = rand() % 1000;
  work_with_file(v1);
}
