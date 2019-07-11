#include <cstdlib>
#include "../leontqev1.h"

// bad index

static int plusOne(int x1) {
  int x2;
  if (x1 >= 10) {
    x2 = 10;
  } else {
    x2 = x1;
  }
  int res = x2 + 1;
  return res;
}

static int buf11[11];
static int innerAccess1(int a) {
  int idx = plusOne(a);
  return buf11[idx];
}

static int buf5[5];
static int innerAccess2() {
  int idx = plusOne(4);
  return buf5[idx];
}

void test_buffer_index() {
  innerAccess1(10);
  innerAccess2();
}
