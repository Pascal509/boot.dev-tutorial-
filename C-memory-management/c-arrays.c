/*
If you're used to Lists in Python, Arrays in C are similar, but a bit lower level.
An array is a fixed-size, ordered collection of elements. Like Python lists, they are
indexed by integers, starting at zero. Unlike Python lists, they can only hold element
of the same type. They are stored in contiguous memory, like structs.

In C, we must iterate over them using a for loop with an index
(or some other conditional loop)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int numbers[5] = {1, 2, 3, 4, 5};

    // Iterate and print each element
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    
    // Update some values
    numbers[1] = 20;
    numbers[3] = 40;

    // Print updated array
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}

/*

// ARRAYS AS POINTERS IN C

// 1. Array Declaration: Here, numbers is an array of 5 integers.
int numbers[5] = {1, 2, 3, 4, 5};


// 2. Array as Pointer: The name 'numbers' acts as a pointer to the
// first element of the array. 'numbers_ptr' is a pointer to the same place as numbers.
int *numbers_ptr = numbers;


// 3. Accessing Elements via Indexing: Access the third element (index 2)
int value = numbers[2];
// OR
// Here, 'numbers + 2' computes the address of the third element,
// and * dereferences it to get the value.
int value = *(numbers + 2);


// 4. Pointer Arithmetic: When you add an integer to a pointer,
// the resulting pointer is offset by that integer times the size
// of the data type.
int *p = numbers + 2;  // p points to the third element
int value = *p;        // value is 3

*/




// Multibyte Arrays

// We can declare an array of 3 Coordinate structs like so:

coordinate_t points[3] = {
  {1, 2, 3},
  {4, 5, 6},
  {7, 8, 9}
};

printf("points[1].x = %d, points[1].y = %d, points[1].z = %d\n",
  points[1].x, points[1].y, points[1].z
);
// points[1].x = 4, points[1].y = 5, points[1].z = 6

// Or we can use a pointer:

coordinate_t *ptr = points;
printf("ptr[1].x = %d, ptr[1].y = %d, ptr[1].z = %d\n",
  (ptr + 1)->x, (ptr + 1)->y, (ptr + 1)->z
);
// ptr[1].x = 4, ptr[1].y = 5, ptr[1].z = 6


// Array Casting
coordinate_t points[3] = {
  {5, 4, 1},
  {7, 3, 2},
  {9, 6, 8}
};

int *points_start = (int *)points;

for (int i = 0; i < 9; i++) {
  printf("points_start[%d] = %d\n", i, points_start[i]);
}


// C Strings library

/*
C Strings Are Simple

i. Unlike other programming languages, C strings do not store their length.
ii. The length of a C string is determined by the position of the null terminator ('\0').
iii. Functions like strlen calculate the length of a string by iterating through the characters
until the null terminator is encountered.
iv. This lack of length storage requires careful management to avoid issues such as buffer
overflows and off-by-one errors during string operations.
*/

// C String Library
// The C standard library provides a comprehensive set of functions to manipulate strings
// in the <string.h> header file. Here are some of the most commonly used functions:

// strcpy: Copies a string to another.
char src[] = "Hello";
char dest[6];
strcpy(dest, src);
// dest now contains "Hello"

// strncpy: Copies a specified number of characters from one string to another.
char src[] = "Hello";
char dest[6];
strncpy(dest, src, 3);
// dest now contains "Hel"
dest[3] = '\0';
// ensure null termination

// strcat: Concatenates (appends) one string to another.
char dest[12] = "Hello";
char src[] = " World";
strcat(dest, src);
// dest now contains "Hello World"

// strncat: Concatenates a specified number of characters from one string to another.
char dest[12] = "Hello";
char src[] = " World";
strncat(dest, src, 3);
// dest now contains "Hello Wo"

// strlen: Returns the length of a string (excluding the null terminator).
char str[] = "Hello";
size_t len = strlen(str);
// len is 5

// strcmp: Compares two strings lexicographically.
char str1[] = "Hello";
char str2[] = "World";
int result = strcmp(str1, str2);
// result is negative since "Hello" < "World"

// strchr: Finds the first occurrence of a character in a string.
char str[] = "Hello";
char *pos = strchr(str, 'l');
// pos points to the first 'l' in "Hello"

// strstr: Finds the first occurrence of a substring in a string.
char str[] = "Hello World";
char *pos = strstr(str, "World");
// pos points to "World" in "Hello World"


// Forward Declaration
/*
 A forward declaration lets the compiler know about the existence
 of a struct type before it's fully defined:
*/
typedef struct SnekObject snekobject_t;

typedef struct SnekObject {
  char *name;
  snekobject_t *child;
} snekobject_t;

snekobject_t new_node(char *name);


/*
Mutual Structs
Forward declarations can also be used when two structs reference each other
(a circular reference). For example, a Person has a Computer and a Computer has a Person:
*/

typedef struct Employee employee_t;
typedef struct Department department_t;

struct Employee {
  int id;
  char *name;
  department_t *department;
};

struct Department {
  char *name;
  employee_t *manager;
};

employee_t create_employee(int id, char *name);
department_t create_department(char *name);

void assign_employee(employee_t *emp, department_t *department);
void assign_manager(department_t *dept, employee_t *manager);
