#include <stdlib.h>
#include <stdio.h>
#include "snekobject.h"



int main() {
  snek_object_t *obj = new_snek_array(2);

  snek_object_t *first = new_snek_string("First");
  snek_object_t *second = new_snek_integer(3);

  snek_array_set(obj, 0, first);
  snek_array_set(obj, 1, second);
  snek_object_t *retrieved_first = snek_array_get(obj, 0);
  snek_object_t *retrieved_second = snek_array_get(obj, 1);
  printf("%s\n",retrieved_first->data.v_string);
  printf("%d\n",retrieved_second->data.v_int);

  free(first->data.v_string);
  free(first);
  free(second);
  free(obj->data.v_array.elements);
  free(obj);



  return 0;
}

