#include "snekobject.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  snek_object_t *int_object = new_snek_integer(42);
  printf("%d\n%d\n",int_object->kind,int_object->data.v_int);
  free(int_object);


  return 0;
}

