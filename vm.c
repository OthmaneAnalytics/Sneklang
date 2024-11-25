#include "vm.h"

vm_t *vm_new() {
  vm_t* vm = (vm_t*) malloc(sizeof(vm_t));
  if (vm == NULL) {
    return NULL;
  }
  vm->frames = stack_new(8);
  return vm;
}

void vm_free(vm_t *vm) {
  stack_free(vm->frames);
  stack_free(vm->objects);
  free(vm);
}

