#include <stdio.h>

#include "exercise.h"


int main() {
  char buffer1[100];
  snek_object_t i1 = new_integer(5);
  format_object(i1, buffer1);


  char buffer2[100];
  snek_object_t s1 = new_string("Hello!");
  format_object(s1, buffer2);


  char buffer3[100];
  snek_object_t i2 = new_integer(2014);
  format_object(i2 , buffer3);


  char buffer4[100];
  snek_object_t s2 = new_string("nvim btw");
  format_object(s2, buffer4);

  printf("%s\n", buffer2);
  
  return 0;
}



