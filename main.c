#include <stdlib.h>

#include "snekobject.h"

int main() {
  snek_object_t *one = new_snek_integer(1);
  snek_object_t *three = new_snek_integer(3);
  snek_object_t *four = snek_add(one, three);
  printf("int\n");
  printf("%d\n",four->data.v_int);

  free(one);
  free(three);
  free(four);

  snek_object_t *one2 = new_snek_float(1.5);
  snek_object_t *three2 = new_snek_float(3.5);
  snek_object_t *five2 = snek_add(one2, three2);
  printf("float\n");
  printf("%f\n",five2->data.v_float);

  free(one2);
  free(three2);
  free(five2);

  snek_object_t *hello = new_snek_string("hello");
  snek_object_t *world = new_snek_string(", world");
  snek_object_t *greeting = snek_add(hello, world);
  printf("string\n");
  printf("%s\n", greeting->data.v_string);

  free(hello->data.v_string);
  free(hello);
  free(world->data.v_string);
  free(world);
  free(greeting->data.v_string);
  free(greeting);

  snek_object_t *repeated = new_snek_string("(repeated)");
  snek_object_t *result1 = snek_add(repeated, repeated);
  printf("repeated string\n");
  printf("%s\n", result1->data.v_string);

  free(repeated->data.v_string);
  free(repeated);
  free(result1->data.v_string);
  free(result1);

  snek_object_t *one3 = new_snek_float(1.0);
  snek_object_t *two3 = new_snek_float(2.0);
  snek_object_t *three3 = new_snek_float(3.0);
  snek_object_t *four3 = new_snek_float(4.0);
  snek_object_t *five3 = new_snek_float(5.0);
  snek_object_t *six3 = new_snek_float(6.0);

  snek_object_t *v1 = new_snek_vector3(one3, two3, three3);
  snek_object_t *v2 = new_snek_vector3(four3, five3, six3);
  snek_object_t *result = snek_add(v1, v2);
  printf("vector of floats\n");
  printf("%f %f %f \n",
         result->data.v_vector3.x->data.v_float, 
         result->data.v_vector3.y->data.v_float, 
         result->data.v_vector3.z->data.v_float);

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

  snek_object_t *one1 = new_snek_integer(1);
  snek_object_t *ones = new_snek_array(2);
  snek_array_set(ones, 0, one1);
  snek_array_set(ones, 1, one1);

  snek_object_t *hi = new_snek_string("hi");
  snek_object_t *hellos = new_snek_array(3);
  snek_array_set(hellos, 0, hi);
  snek_array_set(hellos, 1, hi);
  snek_array_set(hellos, 2, hi);

  snek_object_t *result2 = snek_add(ones, hellos);


  snek_object_t *first = snek_array_get(result2, 0);

  printf("array entry 1 is an int\n");
  printf("%d\n", first->data.v_int);
  snek_object_t *third = snek_array_get(result2, 2);

  printf("array entry 2 is an string\n");
  printf("%s\n", third->data.v_string);
  free(one1);
  free(ones->data.v_array.elements);
  free(ones);

  free(hi->data.v_string);
  free(hi);
  free(hellos->data.v_array.elements);
  free(hellos);
  free(result2->data.v_array.elements);
  free(result2);

  return 0;
}

