#pragma once

typedef struct SneklangVar {
  char type;
  char is_constant;
  char *name;
  int value;
  int scope_level;
} sneklang_var_t;


typedef struct Coordinate {
  int x;
  int y;
  int z;
} coordinate_t;

coordinate_t new_coord(int x, int y, int z);
coordinate_t scale_coordinate(coordinate_t coord, int factor);

