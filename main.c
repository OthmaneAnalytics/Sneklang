#include <stdlib.h>
#include <stdio.h>
#include "snekobject.h"


int main() {
  snek_object_t *x = new_snek_integer(1);
  snek_object_t *y = new_snek_integer(2);
  snek_object_t *z = new_snek_integer(3);
  snek_object_t *vec = new_snek_vector3(x, y, z);

  printf("%d\n%d\n%d\n%d\n",vec->kind,vec->data.v_vector3.x->data.v_int,vec->data.v_vector3.y->data.v_int,vec->data.v_vector3.z->data.v_int);
  free(x);
  free(y);
  free(z);
  free(vec);


  return 0;
}

