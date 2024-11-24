#include <stdio.h>
#include <stdlib.h>

#include "snekobject.h"

int main() {
  snek_object_t *foo = new_snek_integer(1);
  snek_object_t *bar = new_snek_integer(2);
  snek_object_t *baz = new_snek_integer(3);
  printf("foo ref count %d \n ",foo->refcount);
  snek_object_t *vec = new_snek_vector3(foo, bar, baz);
  printf("foo ref count %d \n ",foo->refcount);
  printf("vec ref count %d \n ",vec->refcount);
  refcount_dec(foo);
  printf("foo ref count after foo decrement %d \n ",foo->refcount);
  printf("bar ref count after foo decrement %d \n ",bar->refcount);
  refcount_dec(vec);
  printf("decremented vec");
  printf("vec ref count after decrement %d \n ",vec->refcount);
  //printf("foo ref count %d \n ",foo->refcount);
  return 0;
}

