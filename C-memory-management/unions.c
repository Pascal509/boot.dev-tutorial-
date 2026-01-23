/*
UNIONS IN C

Unions in C can hold one of several types. They're like a
less-strict sum type from the world of functional programming.
The age_or_name_t type can hold either an int or a char *, but
not both at the same time (that would be a struct). 

*/

#include "exercise.h"
#include <stdio.h>

void format_object(snek_object_t obj, char *buffer) {
  switch (obj.kind) {
  case INTEGER:
    sprintf(buffer, "int:%d", obj.data.v_int);
    break;
  case STRING:
    sprintf(buffer, "string:%s", obj.data.v_string);
    break;
  }
}

// don't touch below this line'

snek_object_t new_integer(int i) {
  return (snek_object_t){
      .kind = INTEGER,
      .data = {.v_int = i},
  };
}

snek_object_t new_string(char *str) {
  // NOTE: We will learn how to copy this data later.
  return (snek_object_t){
      .kind = STRING,
      .data = {.v_string = str},
  };
}


//  Union Size

/*
A downside of unions is that the size of the union is the size of the
largest field in the union. Take this example:

This IntOrErrMessage union is designed to hold an int 99% of the time.
However, when the program encounters an error, instead of storing an integer here,
it will store an error message. The trouble is that it's incredibly inefficient
because it allocates 256 bytes for every int that it stores!

Imagine an array of 1000 int_or_err_message_t objects. Even if none of them make use
of the .err field, the array will take up 256 * 1000 = 256,000 bytes of memory! An array
of ints would have only taken 4,000 bytes (assuming 32-bit integers).
*/

typedef union IntOrErrMessage {
  int data;
  char err[256];
} int_or_err_message_t;