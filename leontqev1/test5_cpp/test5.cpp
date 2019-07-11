#include <cstdlib>
#include <iostream>
#include <string>
#include "../leontqev1.h"

using namespace std;

const char *take_pointer(bool cond) {
  std::string s = "Test string";

  if (cond)
    return s.c_str(); // local variable s is destroyed by an automatic
                      // destructor at the end of the function
  else
    return NULL;
}

void test_pointer_to_null() {
  const char *p_s1 =
      take_pointer(true); //Указатель ссылается на удаленную переменную
  std::string s2(p_s1);

  s2.length();
}
// use after free