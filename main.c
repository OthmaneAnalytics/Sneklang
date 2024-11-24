#include <stdio.h>
#include <stdlib.h>

#include "snekobject.h"

int main (){
  snek_object_t *obj = new_snek_integer(10);

  refcount_inc(obj);
  printf("%d\n", obj->refcount);
  free(obj);

  snek_object_t *obj1 = new_snek_float(4.20);

  refcount_inc(obj1);
  refcount_inc(obj1);
  refcount_inc(obj1);
  refcount_inc(obj1);
  refcount_inc(obj1);

  printf("%d\n", obj1->refcount);
  free(obj1);

  refcount_inc(NULL);


  return 0;
}

