/*
The stack is where local variables are stored. When a function is called, a new stack frame
is created in memory to store the function's parameters and local variables. When the function returns,
its entire stack frame is deallocated.
*/
#include "exercise.h"
#include <stdio.h>

// An example function
void create_typist(int uses_nvim) {
  int wpm = 150;
  char name[4] = {'t', 'e', 'e', 'j'};
}

/*
See how with each successive nested function call (printMessageOne, which calls printMessageTwo, which calls
printMessageThree) the memory addresses allocate more and more space?

Update where printMessageTwo and printMessageThree are called from so that all three of the functions use the same stack space.
The offsets printed by printStackPointerDiff should now be different from before. The printStackPointerDiff() calls should
remain at the start of each function.
*/


int main() {
  printMessageOne();
  printMessageTwo();
  printMessageThree();
  return 0;
}

void printMessageOne() {
  const char *message = "Dark mode?\n";
  printStackPointerDiff();
  printf("%s\n", message);
}

void printMessageTwo() {
  const char *message = "More like...\n";
  printStackPointerDiff();
  printf("%s\n", message);
}

void printMessageThree() {
  const char *message = "dark roast.\n";
  printStackPointerDiff();
  printf("%s\n", message);
}

// don't touch below this line

void printStackPointerDiff() {
  static void *last_sp = NULL;
  void *current_sp;
  current_sp = __builtin_frame_address(0);
  long diff = (char *)last_sp - (char *)current_sp;
  if (last_sp == NULL) {
    last_sp = current_sp;
    diff = 0;
  }
  printf("---------------------------------\n");
  printf("Stack pointer offset: %ld bytes\n", diff);
  printf("---------------------------------\n");
}

