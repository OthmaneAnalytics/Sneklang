#include <stdlib.h>

#include "snekobject.h"


snek_object_t *new_snek_float(float value) {
  snek_object_t* s_float = (snek_object_t*) malloc(sizeof(snek_object_t));
  if (s_float == NULL) {
    return NULL;
  }
  s_float->kind = FLOAT;
  s_float->data.v_float = value;
  return s_float;
}

snek_object_t *new_snek_integer(int value) {
  snek_object_t* s_int = (snek_object_t*) malloc(sizeof(snek_object_t));
  if (s_int == NULL) {
    return NULL;
  }
  s_int->kind = INTEGER;
  s_int->data.v_int = value;
  return s_int;
}

