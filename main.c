#include <stdio.h>
#include <stdlib.h>

#include "snekobject.h"


int main() {
  snek_object_t *foo = new_snek_integer(1);
  snek_object_t *bar = new_snek_integer(2);
  snek_object_t *baz = new_snek_integer(3);

  snek_object_t *array = new_snek_array(2);
  printf("ref count of foo %d \n", foo->refcount);  
  printf("ref count of array %d \n", array->refcount);  
  snek_array_set(array, 0, foo); 
  snek_array_set(array, 1, bar);

  printf("ref count of foo after adding foo and bar %d \n", foo->refcount);  
  printf("ref count of array %d \n", array->refcount);  
  snek_array_set(array, 0, baz);
  
  printf("ref count of foo after replacing foo by baz %d \n", foo->refcount);  
  printf("ref count of array %d \n", array->refcount);  
  printf("ref count of baz %d \n", baz->refcount);  
  printf("ref count of foo %d \n", foo->refcount);  

  refcount_dec(array);


  printf("ref count of baz after decrementing array %d \n", baz->refcount);  

  printf("ref count of foo %d \n", foo->refcount);  
  printf("ref count of bar (next we decrement bar) %d \n", bar->refcount);  
  refcount_dec(bar);

  return 0;
}

