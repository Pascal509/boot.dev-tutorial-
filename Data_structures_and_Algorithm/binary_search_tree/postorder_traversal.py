# Implement the recursive postorder method. Here are the algorithm's steps:

# Recursively traverse the left subtree
# Recursively traverse the right subtree
# Visit the value of the current node by appending its value to the visited array
# Return array of visited nodes

class BSTNode:
    def postorder(self, visited):
        if self.left is not None:
            self.left.postorder(visited)
        if self.right is not None:
            self.right.postorder(visited)
        if self.val is not None:
            visited.append(self.val)
        return visited

    # don't touch below this line

    def __init__(self, val=None):
        self.left = None
        self.right = None
        self.val = val

    def insert(self, val):
        if not self.val:
            self.val = val
            return

        if self.val == val:
            return

        if val < self.val:
            if self.left:
                self.left.insert(val)
                return
            self.left = BSTNode(val)
            return

        if self.right:
            self.right.insert(val)
            return
        self.right = BSTNode(val)
