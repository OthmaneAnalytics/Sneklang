#include "snekstack.h"
#include <stdio.h>

int main() {
  stack_t *s = stack_new(3);
  printf("%d\n%d\n", s->count,s->capacity);
  free(s->data);
  free(s);

  return 0;
}

