#include <stdio.h>
#include "coord.h"


int main() {

  coordinate_t A = new_coord(3, 4, 1);
  coordinate_t B = scale_coordinate(A, 2);
  printf("B_x: %d ,B_y: %d , B_z: %d \n", B.x, B.y ,B.z );
  printf("Size of sneklangVar %zu\n", sizeof(sneklang_var_t));
  return 0;
}

