#include "exercise.h"
#include <string.h>
#include <stdio.h>

int main(void){
  TextBuffer dest;
  strcat(dest.buffer, "This thll up the entire buffer.");
  dest.length = 31;
  const char* src = " Extra";
  int result = smart_append(&dest, src);
  printf("%d", result);
}
