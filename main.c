#include "snekobject.h"
#include <stdio.h>
#include <stdlib.h>
int main() {

  snek_object_t *obj = new_snek_integer(42);
  printf("%d\n",snek_length(obj));
  free(obj);

  snek_object_t *obj1 = new_snek_float(3.14);
  printf("%d\n",snek_length(obj1));
  free(obj1);

  snek_object_t *shorter = new_snek_string("hello");

  printf("%d\n",snek_length(shorter));
  snek_object_t *longer = new_snek_string("hello, world");
  printf("%d\n",snek_length(longer));
  free(shorter->data.v_string);
  free(shorter);
  free(longer->data.v_string);
  free(longer);

  snek_object_t *i = new_snek_integer(1);
  snek_object_t *vec = new_snek_vector3(i, i, i);
  printf("%d\n",snek_length(vec));
  free(i);
  free(vec);

  snek_object_t *i1 = new_snek_integer(1);
  snek_object_t *arr = new_snek_array(4);
  snek_array_set(arr, 0, i1);
  snek_array_set(arr, 1, i1);
  snek_array_set(arr, 2, i1);
  printf("%d\n",snek_length(arr));

  free(i1);
  free(arr->data.v_array.elements);
  free(arr);


  return 0;
}

