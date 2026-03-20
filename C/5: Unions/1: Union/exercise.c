#include "exercise.h"
#include <stdio.h>

void format_object(snek_object_t obj, char *buffer) {
  
}


snek_object_t new_integer(int i) {
  return (snek_object_t){
      .kind = INTEGER,
      .data = {.v_int = i},
  };
}

snek_object_t new_string(char *str) {
  return (snek_object_t){
      .kind = STRING,
      .data = {.v_string = str},
  };
}
