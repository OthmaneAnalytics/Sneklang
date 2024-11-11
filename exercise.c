#include <string.h>
#include "exercise.h"

int smart_append(TextBuffer* dest, const char* src) {
  if ( 63 - dest->length < strlen(src)){
    strncpy(dest->buffer , src, 63 - dest->length);
    dest->buffer[63] = '\0';
    dest->length = 64;
    return 1;
  } else {
    strcat(dest->buffer, src);
    dest->length += strlen(src);
    return 0;
  }
}

