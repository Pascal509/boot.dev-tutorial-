# LeetCode: 232. Implement Queue using Stacks
# Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

# Implement the MyQueue class:

# void push(int x) Pushes element x to the back of the queue.
# int pop() Removes the element from the front of the queue and returns it.
# int peek() Returns the element at the front of the queue.
# boolean empty() Returns true if the queue is empty, false otherwise.
# Notes:

# You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
# Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.


class MyQueue:
    def __init__(self):
        self.stack_in = []   # Stack for push operations
        self.stack_out = []  # Stack for pop/peek operations

    def push(self, x: int) -> None:
        # Always push new elements onto stack_in
        self.stack_in.append(x)

    def pop(self) -> int:
        # If stack_out is empty, move elements from stack_in to stack_out
        if not self.stack_out:
            while self.stack_in:
                self.stack_out.append(self.stack_in.pop())
        return self.stack_out.pop() if self.stack_out else None

    def peek(self) -> int:
        # If stack_out is empty, transfer elements first
        if not self.stack_out:
            while self.stack_in:
                self.stack_out.append(self.stack_in.pop())
        return self.stack_out[-1] if self.stack_out else None

    def empty(self) -> bool:
        # Queue is empty only when both stacks are empty
        return not self.stack_in and not self.stack_out
