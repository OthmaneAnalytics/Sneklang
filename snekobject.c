#include <stdlib.h>
#include <string.h>
#include "snekobject.h"

void refcount_dec(snek_object_t *obj) {
  if (obj != NULL) {
    obj->refcount -= 1;
    if (obj->refcount == 0) {
      refcount_free(obj);
    }
  }
}

void refcount_free(snek_object_t *obj) {
  switch (obj->kind) {
    case INTEGER:
      free(obj);
    case FLOAT:
      free(obj);
    case STRING:
      free(obj->data.v_string);
      free(obj);
  }
}

void refcount_inc(snek_object_t *obj) {
  if (obj != NULL) {
    obj->refcount += 1;
  }
}

snek_object_t *_new_snek_object() {
  snek_object_t* obj = (snek_object_t*) malloc(sizeof(snek_object_t));
  if (obj == NULL){
    return NULL;
  }
  obj->refcount = 1;
  return obj;
}

snek_object_t *snek_add(snek_object_t *a, snek_object_t *b) {
  if (a == NULL || b== NULL) {
    return NULL;
  }
  switch (a->kind){
    case INTEGER:
      if (b->kind == INTEGER){
        return new_snek_integer(a->data.v_int + b->data.v_int);
      }
      if (b->kind == FLOAT){
        return new_snek_float( (float) a->data.v_int + b->data.v_float);
      }
      return NULL;
    case FLOAT:
      if (b->kind == INTEGER){
        return new_snek_float( a->data.v_float + (float) b->data.v_int);
      }
      if (b->kind == FLOAT){
        return new_snek_float( a->data.v_float + b->data.v_float);
      }
      return NULL;
    case STRING:
      if (b->kind == STRING) {
        int len = snek_length(a) + snek_length(b);
        char* cat = (char*) calloc(len, sizeof(char));
        strcat( cat, a->data.v_string);
        strcat( cat, b->data.v_string);
        snek_object_t* obj = new_snek_string(cat);
        free(cat);
        return obj;
      }
      return NULL;
    case VECTOR3:
      if (b->kind == VECTOR3) {
        return new_snek_vector3(
          snek_add(a->data.v_vector3.x, b->data.v_vector3.x),
          snek_add(a->data.v_vector3.y, b->data.v_vector3.y),
          snek_add(a->data.v_vector3.z, b->data.v_vector3.z)
        );
      }
      return NULL;
    case ARRAY:
      if (b->kind == ARRAY) {
        snek_object_t* arr = new_snek_array(snek_length(a) + snek_length(b));
        for (int i = 0; i < snek_length(a); i++) {
             snek_array_set(arr , i, snek_array_get(a, i));
             }
        int k = snek_length(a);
        for (int i = 0; i < snek_length(b); i++) {
             snek_array_set(arr , k + i, snek_array_get(b, i));
             }
        return arr;
      }
      return NULL;
    default:
      return NULL;
  }
}


int snek_length(snek_object_t *obj) {
  if (obj == NULL) {
    return -1;
  }
  switch (obj->kind){
    case INTEGER:
      return 1;
    case FLOAT:
      return 1;
    case STRING:
      return (int) strlen(obj->data.v_string);
    case VECTOR3:
      return 3;
    case ARRAY:
      return (int) obj->data.v_array.size;
    default:
      return -1;
  }
}

bool snek_array_set(snek_object_t *snek_obj, size_t index, snek_object_t *value) {
  if (snek_obj == NULL || snek_obj->kind != ARRAY || index > snek_obj->data.v_array.size){
    return false;
  }
  snek_obj->data.v_array.elements[index] = value;
  return true;
}

snek_object_t *snek_array_get(snek_object_t *snek_obj, size_t index) { 
  if (snek_obj == NULL || snek_obj->kind != ARRAY || index > snek_obj->data.v_array.size){
    return NULL;
  }
  return snek_obj->data.v_array.elements[index];
}

snek_object_t *new_snek_array(size_t size) {
  snek_object_t *obj = _new_snek_object();
  if (obj == NULL) {
    return NULL;
  }

  snek_object_t **elements = calloc(size, sizeof(snek_object_t *));
  if (elements == NULL) {
    free(obj);
    return NULL;
  }

  obj->kind = ARRAY;
  obj->data.v_array = (snek_array_t){.size = size, .elements = elements};

  return obj;
}

snek_object_t *new_snek_vector3(
    snek_object_t *x, snek_object_t *y, snek_object_t *z
) {
  if (x == NULL || y == NULL || z == NULL) {
    return NULL;
  }

  snek_object_t *obj = _new_snek_object();
  if (obj == NULL) {
    return NULL;
  }

  obj->kind = VECTOR3;
  obj->data.v_vector3 = (snek_vector_t){.x = x, .y = y, .z = z};

  return obj;
}

snek_object_t *new_snek_integer(int value) {
  snek_object_t *obj = _new_snek_object();
  if (obj == NULL) {
    return NULL;
  }

  obj->kind = INTEGER;
  obj->data.v_int = value;
  return obj;
}

snek_object_t *new_snek_float(float value) {
  snek_object_t *obj = _new_snek_object();
  if (obj == NULL) {
    return NULL;
  }

  obj->kind = FLOAT;
  obj->data.v_float = value;
  return obj;
}

snek_object_t *new_snek_string(char *value) {
  snek_object_t *obj = _new_snek_object();
  if (obj == NULL) {
    return NULL;
  }

  int len = strlen(value);
  char *dst = malloc(len + 1);
  if (dst == NULL) {
    free(obj);
    return NULL;
  }

  strcpy(dst, value);

  obj->kind = STRING;
  obj->data.v_string = dst;
  return obj;
}

