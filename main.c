#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "exercise.h"

int main() {
  char *a = "Hello";
  char *b = "Goodbye";

  swap_strings(&a, &b);
  printf("hello %s\n goodbye %s\n", a , b);
  return 0;
}

