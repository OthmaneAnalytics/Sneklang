#include "snekobject.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  snek_object_t *int_object = new_snek_float(42.457);
  printf("%d\n%f\n",int_object->kind,int_object->data.v_float);
  free(int_object);


  return 0;
}

