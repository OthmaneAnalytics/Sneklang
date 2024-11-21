#include <stdlib.h>
#include <string.h>
#include "snekobject.h"

snek_object_t *new_snek_array(size_t size) {
  snek_object_t* obj = (snek_object_t*) malloc(sizeof(snek_object_t));  
  if (obj == NULL){
    return NULL;
  }
  snek_object_t** arr = (snek_object_t**) calloc(size, sizeof(snek_object_t*));  
  if (arr == NULL){
    free(obj);
    return NULL;
  }
  obj->kind = ARRAY;
  snek_array_t n_array = {.size = size, .elements = arr};
  obj->data->v_array = n_array;
  return obj;
}

snek_object_t *new_snek_vector3(
    snek_object_t *x, snek_object_t *y, snek_object_t *z
) {
  if ( x == NULL || y == NULL || z == NULL) {
    return NULL;
  }
  snek_object_t* obj = (snek_object_t*) malloc(sizeof(snek_object_t));
  if (obj == NULL){
    return NULL;
  }
  obj->kind = VECTOR3;
  snek_vector_t* vect = (snek_vector_t*) malloc(sizeof(snek_vector_t));
  if (vect == NULL){
    free(obj);
    return NULL;
  }
  vect->x = x;
  vect->y = y;
  vect->z = z;
  obj->data.v_vector3 = *vect;
  return obj;
}

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

