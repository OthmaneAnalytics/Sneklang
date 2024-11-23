#include <stdlib.h>
#include <stdio.h>

#include "snekobject.h"

int main() {
  snek_object_t *one = new_snek_integer(1);
  snek_object_t *three = new_snek_integer(3);
  snek_object_t *four = snek_add(one, three);


  free(one);
  free(three);
  free(four);

  snek_object_t *one = new_snek_float(1.5);
  snek_object_t *three = new_snek_float(3.5);
  snek_object_t *five = snek_add(one, three);

  free(one);
  free(three);
  free(five);

  snek_object_t *hello = new_snek_string("hello");
  snek_object_t *world = new_snek_string(", world");
  snek_object_t *greeting = snek_add(hello, world);


  free(hello->data.v_string);
  free(hello);
  free(world->data.v_string);
  free(world);
  free(greeting->data.v_string);
  free(greeting);

  snek_object_t *repeated = new_snek_string("(repeated)");
  snek_object_t *result = snek_add(repeated, repeated);

  free(repeated->data.v_string);
  free(repeated);
  free(result->data.v_string);
  free(result);

  snek_object_t *one = new_snek_float(1.0);
  snek_object_t *two = new_snek_float(2.0);
  snek_object_t *three = new_snek_float(3.0);
  snek_object_t *four = new_snek_float(4.0);
  snek_object_t *five = new_snek_float(5.0);
  snek_object_t *six = new_snek_float(6.0);

  snek_object_t *v1 = new_snek_vector3(one, two, three);
  snek_object_t *v2 = new_snek_vector3(four, five, six);
  snek_object_t *result = snek_add(v1, v2);

  free(v1->data.v_vector3.x);
  free(v1->data.v_vector3.y);
  free(v1->data.v_vector3.z);
  free(v1);

  free(v2->data.v_vector3.x);
  free(v2->data.v_vector3.y);
  free(v2->data.v_vector3.z);
  free(v2);

  free(result->data.v_vector3.x);
  free(result->data.v_vector3.y);
  free(result->data.v_vector3.z);
  free(result);

  snek_object_t *one = new_snek_integer(1);
  snek_object_t *ones = new_snek_array(2);
  snek_array_set(ones, 0, one);
  snek_array_set(ones, 1, one);

  snek_object_t *hi = new_snek_string("hi");
  snek_object_t *hellos = new_snek_array(3);
  snek_array_set(hellos, 0, hi);
  snek_array_set(hellos, 1, hi);
  snek_array_set(hellos, 2, hi);

  snek_object_t *result = snek_add(ones, hellos);


  snek_object_t *first = snek_array_get(result, 0);

  snek_object_t *third = snek_array_get(result, 2);

  free(one);
  free(ones->data.v_array.elements);
  free(ones);

  free(hi->data.v_string);
  free(hi);
  free(hellos->data.v_array.elements);
  free(hellos);
  free(result->data.v_array.elements);
  free(result);

  return 0;
}

