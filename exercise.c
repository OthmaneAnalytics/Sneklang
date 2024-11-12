#include <stdio.h>
#include <stdlib.h>
#include "exercise.h"

char* get_full_greeting(char *greeting, char *name, int size) {
  char *full_greeting = (char*)malloc(100 * sizeof(char));
  snprintf(full_greeting, 100, "%s %s", greeting, name);
  return full_greeting;
}

