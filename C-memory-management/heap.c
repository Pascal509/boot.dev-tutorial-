// HEAP
/*
"The heap", as opposed to "the stack", is a pool of long-lived memory shared across the entire program.
Stack memory is automatically allocated and deallocated as functions are called and returned, but heap memory
is allocated and deallocated as-needed, independent of the burdensome shackles of function calls.

When you need to store data that outlives the function that created it, you'll send it to the heap.
The heap is called "dynamic memory" because it's allocated and deallocated as needed. Take a look at new_int_array:
*/
#include "exercise.h"
#include <stdio.h>
#include <stdlib.h>

int *new_int_array(int size) {
  int *new_arr = (int*)malloc(size * sizeof(int)); // Allocate memory
  if (new_arr == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(1); // Exit if allocation fails
  }
  return new_arr;
}

/*
Run the get_full_greeting function in its current state. If you take a look at the main.c file, you'll notice that
it's testing to ensure that a pointer to stack memory isn't returned (which you never should do, because it's undefined behavior).
Fix the get_full_greeting function so that it allocates memory on the heap and returns a pointer to that memory. Use the provided
size parameter to allocate enough space for the resulting string, be sure to account for the size of each char.

*/


char *get_full_greeting(char *greeting, char *name, int size) {
  char *full_greeting = (char *)malloc(size * sizeof(char));
  if (full_greeting == NULL) {
    return NULL;
  }
  snprintf(full_greeting, size, "%s %s", greeting, name);
  return full_greeting;
}
