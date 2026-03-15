#pragma once

typedef struct Coordinate {
  int x;
  int y;
  int z;
}coordinate_t;
// _t serve para indicar um tipo (boa pratica)

coordinate_t new_coord(int x, int y, int z);
coordinate_t scale_coordinate(coordinate_t coord, int factor);
