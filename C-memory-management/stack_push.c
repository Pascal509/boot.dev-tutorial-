#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <stddef.h>


typedef struct Stack {
  size_t count;
  size_t capacity;
  void **data;
} stack_t;

stack_t *stack_new(size_t capacity);
void stack_push(stack_t *stack, void *obj);



void stack_push(stack_t *stack, void *obj) {
  if (stack->count == stack->capacity) {
    stack->capacity *= 2;
    void **temp = realloc(stack->data, stack->capacity * sizeof(void *));
    if (temp == NULL) {
      stack->capacity /= 2;
      return;
    }
    stack->data = temp;
  }
  stack->data[stack->count] = obj;
  stack->count++;
  return;
}

// don't touch below this line

stack_t *stack_new(size_t capacity) {
  stack_t *stack = malloc(sizeof(stack_t));
  if (stack == NULL) {
    return NULL;
  }

  stack->count = 0;
  stack->capacity = capacity;
  stack->data = malloc(stack->capacity * sizeof(void *));
  if (stack->data == NULL) {
    free(stack);
    return NULL;
  }

  return stack;
}

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
