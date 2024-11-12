#include <stdio.h>
#include <stdlib.h>

#include "exercise.h"

int *allocate_scalar_list(int size, int multiplier) {
  int *arr = (int *)malloc(size *sizeof(int));
  if(arr == NULL){
    return NULL;
  }
  for (int i = 0; i<size; i++){
    arr[i] = multiplier * i;
  }
  return arr;
}

