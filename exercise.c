#include "stdlib.h"

#include "exercise.h"

void allocate_int(int **pointer_pointer, int value) {
  int *val = (int*) malloc(sizeof(int));
  *pointer_pointer = val;
  **pointer_pointer = value;
  
}

