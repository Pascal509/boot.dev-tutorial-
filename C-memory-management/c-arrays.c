/*
If you're used to Lists in Python, Arrays in C are similar, but a bit lower level.
An array is a fixed-size, ordered collection of elements. Like Python lists, they are
indexed by integers, starting at zero. Unlike Python lists, they can only hold element
of the same type. They are stored in contiguous memory, like structs.

In C, we must iterate over them using a for loop with an index
(or some other conditional loop)
*/

#include <stdio.h>

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