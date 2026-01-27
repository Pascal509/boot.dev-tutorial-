#include <stdio.h>

// int main() {
//     printf("Starting Python Interpreter...\n");
//     return 0;
// }


//Single Comment In C

// int main() {
// /*
// This is a multiple line comment
// A normal conversation between me and Groot
// */
//     printf("Hey there!!!\n");
//     printf("I am Groot\n");
//     printf("Lets roll\n");
// }

/*
Basic Types
int - An integer
float - A floating point number
char - A character
char * - An array of characters (more on this later... 
if you think about it, sounds kinda like a string doesn't it?)
*/

// int main() {
//     int max_recursive_calls = 100;
//     char io_mode = 'p';
//     float throttle_speed = 0.2;
//     char *sneklang_title = "Sneklang";

//     //dont touch below this line
//     printf("Max recursive calls: %d \n", max_recursive_calls);
//     printf("IO mode %c \n", io_mode);
//     printf("throttle speed: %f\n", throttle_speed);
//     printf("Sneklang title: %s\n", sneklang_title);
//     return 0;
// }

/*
In C, changing the type of an existing variable is not allowed:
However, a variable's value can change
int main() {
    char *max_threads = "5";

    // call badcop
    // this is illegal
    max_threads = 5;
}
*/
int main() {
    int x = 5;
    x = 10; // this is ok
    x = 15; // still ok

    /*We can use the const type qualifier, if we want to create a value that cant change.*/
    // const int x = 5;
}

float add(int x, int y) {
    return (float)(x + y);
}


int can_access_registry(int is_premium, int reputation, int has_2fa) {
  if (is_premium) {
    return 1;
  }
  if (reputation >= 100 && has_2fa) {
    return 1;
  }
  return 0;
}

//for loops
void print_numbers(int start, int end) {
  for (int i = start; i <= end; i++) {
    printf("%d\n", i);
  }
}

//while loops

void print_numbers_reverse(int start, int end) {
  while(start >= end) {
    printf("%d\n", start);
    start--;
  }
}

//The do while loop guarantees that the loop body is executed at least once,
// even if the condition is false initially.
void print_numbers_reverse(int start, int end) {
  do {
    printf("%d\n", start);
    start--;
  } while (start >= end);
}
