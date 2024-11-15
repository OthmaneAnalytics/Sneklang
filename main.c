#include "snekstack.h"
#include <stdio.h>


int main() {
  stack_t *s = stack_new(2);

  int a = 1;

  stack_push(s, &a);
  stack_push(s, &a);
  stack_push(s, &a);
  printf("%zu\n%zu\n",s->count,s->capacity);
  free(s->data);
  free(s);

  return 0;
}

