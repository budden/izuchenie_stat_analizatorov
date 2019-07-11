#include <cstdlib>
#include "../leontqev1.h"

void ttt(const int *nptr) {};
void ttt2(const int *nptr) {};
typedef void (*NoConstType)(int*);

int foo10595327(int b) {
  void (*fp)(int *);
  if (b > 5)
    fp = (NoConstType)ttt2;
  else
    fp = (NoConstType)ttt;
  int x = 3;
  int y = x + 1;
  int *p = 0;
  fp(&y);
  if (x == y)
      return *p; // no-warning
  return 0;
}

struct InvalidateArgs {
  void ttt(const int &nptr) {};
  virtual void vttt(const int *nptr) {};
};

struct ChildOfInvalidateArgs: public InvalidateArgs {
  virtual void vttt(const int *nptr){};
};

void declarationFun(int x) {
  InvalidateArgs t;
  x = 3;
  int y = x + 1;
  int *p = 0;
  t.ttt(y);
  if (x == y)
      y = *p; // no-warning
}

void virtualFun(int x) {
  ChildOfInvalidateArgs t;
  InvalidateArgs *pt = &t;
  x = 3;
  int y = x + 1;
  int *p = 0;
  pt->vttt(&y);
  if (x == y)
      y = *p; // no-warning
}

void test_ps_no_errors2(){
  int i1 = rand() % 10;

  foo10595327(i1);
  declarationFun(i1);
  virtualFun(i1);
}
