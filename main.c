#include <stdio.h>
#include <stdlib.h>
#include "exercise.h"

int main(){
  const int num_lists = 50000;
  for (int i = 0; i < num_lists; i++) {
    int *lst = allocate_scalar_list(50000, 2);
    if (lst == NULL) {
      printf("Failed to allocate list\n");
      return 1;
    } else {
      free(lst);
      printf("Allocated list %d\n", i);
    }
  }
  return 0;
}

