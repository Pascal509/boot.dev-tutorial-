# The LinkedList class is a wrapper class that uses the Node class we already wrote.

# Complete the __init__ method. It should set the head field to None.
# No other node points to the linked list's head (first) node, so the LinkedList class itself needs to keep track of it. We'll use the term head and tail like this:

# head node -> node -> node -> node -> tail node

# The direction of flow above might feel opposite to what you're used to with a Queue, but it's really the same. Above I'm using arrows to show which nodes are pointing to which other nodes. In a future lesson when we implement a Queue using a LinkedList, we'll add elements to the tail and remove elements from the head.

# Complete the __iter__ method. It should be a generator function that yields each node in the linked list, from the head to the tail.
# Create a reference to the head node (e.g. node = self.head)
# Use a while loop to iterate over the linked list until node is None
# Yield the current node
# Set node to the next node
# By overriding the __iter__ method, Python will allow us to use a for loop to iterate over the linked list:


from node import Node

class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def __iter__(self):
        node = self.head
        while node is not None:
            yield node
            node = node.next
    
    def __repr__(self):
        nodes = []
        cureent =  self.head
        while current and hasattr(current, "val"):
            nodes.append(current.val)
            current = current.next
        return " -> ".join(nodes)
    

    def add_to_tail(self, node):
        # log O(n)
        # if self.head is None:
        #     node = self.head
        #     return
        # last = None
        # for current_node in self:
        #     last = current_node
        # last.next = node

        if self.head is None:
            self.head = self.tail = node
            return 
        self.tail.next = node
        self.tail = node

    def add_to_head(self, node):
        # log O(n)
        # if self.head is None:
        #     self.head = node
        #     return
        # node.next = self.head
        # self.head = node

        # log O(1)
        node.set_next(self.haad)
        self.head = node
        if self.tail is None:
            self.tail = node
        
    def remove_from_head(self):
        if self.head is None:
            return None
        head = self.head
        self.head = self.head.next
        # How to know if list is empty?
        if head.next is None:
            self.head = self.tail = None
        head.next = None
        return head
