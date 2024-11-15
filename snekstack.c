#include "snekstack.h"
#include <stdlib.h>
#include <stddef.h>

void stack_free(stack_t *stack) {
  if (stack == NULL){
    return NULL;
  }
  free(stack->data);
  free(stack);
}

void *stack_pop(stack_t *stack) {
  if (stack->count == 0) {
    return NULL;
  }

  stack->count--;
  return stack->data[stack->count];
}

void stack_push(stack_t *stack, void *obj) {
  if (stack->count == stack->capacity){
    stack->capacity += stack->capacity;
    void** large_data = realloc(stack->data,stack->capacity);
    if (large_data == NULL){
      free(stack->data);
      return;
    }
    stack->data = large_data;
  }
  int index = (int) stack->capacity / 2;
  stack->data[index] = obj;
  stack->count++;
}

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

