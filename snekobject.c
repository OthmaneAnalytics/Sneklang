#include <stdlib.h>
#include <string.h>
#include "snekobject.h"

snek_object_t *new_snek_string(char* value) {
  snek_object_t* s_string = (snek_object_t*) malloc(sizeof(snek_object_t));
  if (s_string == NULL) {
    return NULL;
  }
  int s_len = strlen(value);
  char* s = (char*) malloc(s_len * sizeof(char));
  if (s == NULL){
    free(s_string);
    return NULL;
  }
  strcpy( s, value);
  s_string->kind = STRING;
  s_string->data.v_string = s;
  return s_string;
}



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

