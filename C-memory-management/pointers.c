// Void pointers

#include <stdio.h>
#include <stdlib.h>

typedef enum SnekObjectKind {
  INTEGER,
  FLOAT,
  BOOL,
} snek_object_kind_t;

typedef struct SnekInt {
  char *name;
  int value;
} snek_int_t;

typedef struct SnekFloat {
  char *name;
  float value;
} snek_float_t;

typedef struct SnekBool {
  char *name;
  unsigned int value;
} snek_bool_t;

// int main() {
//     int number = 42;

//     void *generic_ptr = &number;

//     // printf("Value of number: %d\n", *generic_ptr);
//     printf("Value of number: %d\n", *(int *)generic_ptr);
// }

/*
This exercise dynamically interprets and stores the values in memory,
snek_zero_out function. It accepts a generic pointer to one of:

snek_int_t
snek_float_t
snek_bool_t

It should "zero out" the .value field of the struct by setting it to the zero value of its type.
Use the kind parameter to figure out which type of struct you are working with.

When working with pointers and dereferencing them, parentheses usage is essential. Consider the following
examples:

((some_struct_t*)ptr)->field means casting is applied to ptr and then the field is obtained.
(some_struct_t*)ptr->field means casting is applied to ptr->field.
*/

void snek_zero_out(void *ptr, snek_object_kind_t kind) {
  switch (kind) {
  case INTEGER:
    ((snek_int_t *)ptr)->value = 0;
    break;
  case FLOAT:
    ((snek_float_t *)ptr)->value = 0.0;
    break;
  case BOOL:
    ((snek_bool_t *)ptr)->value = 0;
    break;
  }
}

int main() {
    snek_int_t my_int = {.name = "age", .value = 42};
    snek_float_t my_float = {.name = "pi", .value = 3.14};
    snek_bool_t my_bool = {.name = "is_valid", .value = 1};

    snek_zero_out(&my_int, INTEGER);
    snek_zero_out(&my_float, FLOAT);
    snek_zero_out(&my_bool, BOOL);

    printf("int value: %d\n", my_int.value);
    printf("float value: %f\n", my_float.value);
    printf("bool value: %u\n", my_bool.value);

    return 0;
}
