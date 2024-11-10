#include <stdio.h>
#include "coordinate.h"

coordinate_t new_coordinate(int x, int y, int z) {
  return (coordinate_t){.x = x, .y = y, .z = z};
}

int main(void){

  coordinate_t coord = new_coordinate(1,3,6);
  coordinate_update_x(coord,10);
  printf("x %d, y %d, z %d\n",coord.x, coord.y, coord.z);
  coordinate_t coord2 = coordinate_update_and_return_x(coord, 10);
  printf("x %d, y %d, z %d\n",coord2.x, coord2.y, coord2.z);
  
  return 0;
}
