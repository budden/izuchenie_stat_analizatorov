#include <cstdlib>
#include <fstream>
#include <iostream>
#include "../leontqev1.h"

using namespace std; // Should find no errors
static void work_with_file(int condition) {
  ofstream myfile;
  int flag;
  if (condition) {
    myfile.open("example.txt");
    flag = 1;
  } else {
    flag = 0;
  }

  if (flag) {
    myfile.close();
  }
}

void test_ps_no_errors1() {
  int v1 = rand() % 1000;
  work_with_file(v1);
}
// Should find no errors