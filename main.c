#include <stdlib.h>
#include "exercise.h"
#include <stdio.h>

int main() {
  int *pointer = NULL;
  allocate_int(&pointer, 10);
  printf("%d\n",*pointer);

  free(pointer);

  int value = 5;
  *pointer = &value;
  allocate_int(&pointer, 20);
  printf("%d\n",*pointer);
  free(pointer);

}

