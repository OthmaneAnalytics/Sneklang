#include <stdlib.h>
#include <stdio.h>
#include "snekobject.h"


int main(void){

  snek_object_t *obj = new_snek_array(2);
  printf("%d\n%zu\n",obj->kind,obj->data.v_array.size);


  free(obj->data.v_array.elements);
  free(obj);

  return 0;
}

