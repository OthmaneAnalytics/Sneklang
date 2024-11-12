#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "exercise.h"

int main() {

  char *result1 = get_full_greeting("Hello", "Alice", 20);
  printf("%s\n",result1);
  free(result1);

  char *result2 = get_full_greeting("Hey", "Bob", 4);
  printf("%s\n",result2);
  free(result2);


}


