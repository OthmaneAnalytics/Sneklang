#include <stdio.h>
#include <stdlib.h>

#include "vm.h"

int main() {
  vm_t *vm = vm_new();
  vm_new_frame(vm);
  vm_free(vm);

  vm_t *vm1 = vm_new();
  vm_new_frame(vm1);
  vm_free(vm1);

  return 0;
}

