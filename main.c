#include <stdio.h>
#include <stdlib.h>

#include "snekobject.h"

int main() {
  snek_object_t *obj = new_snek_integer(10);
  printf("%d\n", obj->refcount);
  refcount_inc(obj);
  printf("%d\n", obj->refcount);

  refcount_inc(obj);
  printf("%d\n", obj->refcount);

  refcount_dec(obj);
  printf("%d\n", obj->refcount);

  refcount_dec(obj);
  printf("%d\n", obj->refcount);


  return 0;
}

