#include "exercise.h"
#include <stdio.h>

int main() {
  snek_int_t integer;
  integer.value = 42;
  printf("%d\n",integer.value);
  snek_zero_out(&integer, INTEGER);
  printf("%d\n",integer.value);



  snek_float_t float_num;
  float_num.value = 3.14;
  printf("%f\n",float_num.value);
  snek_zero_out(&float_num, FLOAT);
  printf("%f\n",float_num.value);

  snek_bool_t boolean;
  boolean.value = 1;
  printf("%d\n",boolean.value);
  snek_zero_out(&boolean, BOOL);
  printf("%d\n",boolean.value);



  return 0;
}

