// CALLOC

#include <stdio.h>
#include <stdlib.h>

int main() {
    // calloc() = Contiguous Allocation. Allocates memory dynamically
    // to a specified number of bytes of memory on the heap and returns a
    // pointer to the allocated memory. This memory / allocated bytes is initialised to 0.
    // malloc() is faster, but calloc() leads to less bugs.
    // calloc(#, size)

    int size = 0;
    printf("Enter the number of players: ");
    scanf("%d", &size);

    int *scores = calloc(size, sizeof(int));

    if (scores == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        printf("Enter score #%d: ", i + 1);
        scanf("%d", &scores[i]);
    }

    for (int i = 0; i < size; i++) {
        printf("%d\n", scores[i]);
    }

    free(scores);
    scores = NULL;

    return 0;

}