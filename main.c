#include <stdio.h>
#include <stdlib.h>

#include "sneknew.h"
#include "snekobject.h"
#include "vm.h"

int main() {
  vm_t *vm = vm_new();
  snek_object_t *obj = new_snek_integer(vm, 5);
  vm_new_frame(vm);
  free(obj);
  vm_free(vm);

  return 0;
}

