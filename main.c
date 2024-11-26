#include <stdio.h>
#include <stdlib.h>

#include "sneknew.h"
#include "vm.h"

int main() {
  vm_t *vm = vm_new();
  new_snek_integer(vm, 5);
  new_snek_string(vm, "hello");
  vm_new_frame(vm);
  vm_free(vm);

  return 0;
}

