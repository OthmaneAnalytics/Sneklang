#include "snekstack.h"
#include <stdlib.h>

stack_t *stack_new(size_t capacity) {
  stack_t* Stack = (stack_t*) malloc(sizeof(stack_t));
  if(Stack == NULL){
    return NULL;
  }
  Stack->count = 0;
  Stack->capacity = capacity;
  Stack->data = malloc(capacity*sizeof(void*));
  if(Stack->data == NULL){
    free(Stack);
    return NULL;
  }
  return Stack;
}

