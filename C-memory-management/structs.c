//Structs 
#include "structs.h"

//different ways to initialize a struct

struct City {
  char *name;
  int lat;
  int lon;
};

//Zero Initializer: This sets all the fields to 0 values.
// int main() {
//   struct City c = {0};
// }

//Positional Initializer
// int main() {
//   struct City c = {"San Francisco", 37, -122};
// }

//With assigned to a Designated Initializer
int main() {
  struct City c = {
    .name = "San Francisco",
    .lat = 37,
    .lon = -122
  };
}

struct Coordinate new_coord(int x, int y, int z) {
  // ?
  struct Coordinate coord = {
    .x = x,
    .y = y,
    .z = z};
  return coord;
}

struct Human become_older(int age, char *name) {
    struct Human h = {.age = age, .name = name};
    h.age++;
    return h;
}