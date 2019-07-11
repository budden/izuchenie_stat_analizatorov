#include <cstdlib>
#include "../leontqev1.h"

static int g;
void null_pointer_dereference(int a, int b) {
  int *p = 0;
  if (a > b) {
    p = &g;
  }
  if (a > b + 1) {
    *p = 6;
  }
}

void test_null_pointer_dereference_warning() {
  null_pointer_dereference(5, 7);
  null_pointer_dereference(7, 6);
  null_pointer_dereference(6, 6);
}
// unreachable code