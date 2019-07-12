#include <stdlib.h>
#include <stdio.h>
#include "../leontqev1.h"

void test_free(void *p) { free(p); }

void test_bar() {
  void *q = malloc(1);
  free(q);
  test_free(q);
}

void test_baz() {
  void *q = malloc(1);
  test_free(q);
  free(q);
}

void free_mem_by_pts(int *x, int *p, int m) {
  if (p == 0) {
  } else {
    if (x == 0) {
    } else {
      test_free(p);
      p = 0;
    }
  }
  if (m == 0) {
  } else {
    test_free(x);
  }
  free(x);
  free(p);
}

void test_path_sensitiv_no_exceptions() {
  int *x = (int *)malloc(1);
  int *p = (int *)malloc(1);

  free_mem_by_pts(x, p, 0);
  // Dolzhny bytq preduprezhdenija ob ispolqzovanii posle osvobozhdenija 'x' i 'p'
  free_mem_by_pts(0, p, 0);
  free_mem_by_pts(x, 0, 0);
  free_mem_by_pts(0, 0, 0);
  free_mem_by_pts(0, p, 5);
  free_mem_by_pts(0, 0, 5);
}

void test_path_sensitiv_wwith_errors() {
  int *x = (int *)malloc(1);
  int *p = (int *)malloc(1);

  free_mem_by_pts(x, p, 5); // Oshibka dvojjnogo osvobozhdenija pamjati
  free_mem_by_pts(x, 0, 5); // Oshibka dvojjnogo osvobozhdenija pamjati
}

#define SIMPLE_MACRO(x) "a" # x
#define COMPLEX_MACRO(x,y) SIMPLE_MACRO(x) # y


void mem_multiple_free_c() {
  test_path_sensitiv_no_exceptions(); // Kod ne vyzyvajushhijj padenija

  test_bar(); // Oshibka dlja vyjavlenija kontekstno-chuvstvitelqnym analizom
  test_baz(); // Oshibka dlja vyjavlenija kontekstno-chuvstvitelqnym analizom

  test_path_sensitiv_wwith_errors(); // Oshibka dlja vyjavlenija analizom,
                                    // chuvstvitelqnym k putjam vypolnenija
  printf(COMPLEX_MACRO("aaa","bbb"));
}


