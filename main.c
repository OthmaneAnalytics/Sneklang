#include <stdio.h>
#include <stdlib.h>

#include "snekobject.h"

int main() {
  snek_object_t *obj = new_snek_integer(10);
  printf("%d\n",obj->data.v_int);
  free(obj);

  snek_object_t *obj2 = new_snek_float(42.0);
  printf("%f\n",obj2->data.v_float);
  free(obj2);

  return 0;
}

