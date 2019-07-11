#include <stdlib.h>
#include "../leontqev1.h"

char buffer[10];
void init_pointer(char **p, int a) {
  if (a > 0)
    *p = &buffer[0]; // *p <> NULL if a > 0
  if (a >= 0)
    **p = '\0'; // deref(*p) if a == 0
}

void test_null_pointer_dereference_c() {
  char str[] = "hello word";
  char *ptr1 = str;

  char *ptr2 = NULL;

  init_pointer(&ptr1, 0); // Обнуление строки
  init_pointer(&ptr1, 3); // Обнуление указателя на строку.

  init_pointer(&ptr2, 0); // Обнуление строки по нулевому указателю. Ошибка
}