#include <stdlib.h>
#include <stdio.h>
#include "snekobject.h"

int main() {
  char *input = "Hello, World!";
  snek_object_t *obj = new_snek_string(input);
  printf("%s\n",obj->data.v_string);

  free(obj->data.v_string);
  free(obj);

  return 0;
}

