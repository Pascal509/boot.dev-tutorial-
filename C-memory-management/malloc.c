#include <stdio.h>
#include <stdlib.h>

int main() {
    // malloc() = a function in C that dynamically allocates a specified number 
    // of bytes in memory on the heap and returns a pointer to the allocated memory.

    int size = 0;
    printf("These are my grades: ");
    scanf("%d", &size);

    char *grades = malloc(size * sizeof(char));

    // int size = sizeof(grades) / sizeof(grades[0])

    if (grades == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        printf("Enter grade #%d: ", i + 1);
        scanf(" %c", &grades[i]);
    }

    for (int i = 0; i < size; i++) {
        printf("%c \n", grades[i]);
    }

    free(grades);
    grades = NULL;

    return 0;
}