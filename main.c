#include "exercise.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int size = 5;
  int multiplier = 2;
  int *result = allocate_scalar_list(size, multiplier);
  for (int i = 0; i < size; i++) {
  printf("%d\n",result[i]);
  }
  free(result);
}


