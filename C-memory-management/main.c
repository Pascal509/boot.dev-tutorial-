#include <stdio.h>
#include <assert.h>

int main(void) {
    // Create a new stack with initial capacity 2
    stack_t *stack = stack_new(2);
    assert(stack != NULL);

    int a = 10;
    int b = 20;
    int c = 30;

    // Push elements onto the stack
    stack_push(stack, &a);
    stack_push(stack, &b);

    // At this point, stack is full
    assert(stack->count == 2);
    assert(stack->capacity == 2);

    // This push should trigger a resize
    stack_push(stack, &c);

    // Verify stack state after resize
    assert(stack->count == 3);
    assert(stack->capacity == 4);

    // Access and print values (cast back from void *)
    printf("Top elements:\n");
    printf("%d\n", *(int *)stack->data[0]);
    printf("%d\n", *(int *)stack->data[1]);
    printf("%d\n", *(int *)stack->data[2]);

    // Cleanup
    free(stack->data);
    free(stack);

    printf("Stack test passed ✅\n");
    return 0;
}
