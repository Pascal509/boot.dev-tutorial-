class Trie:
    def add(self, word):
        current = self.root
        for i in word:
            if i not in current:
                current[i] = {}
            current = current[i]

        current[self.end_symbol] = True
                

    # don't touch below this line

    def __init__(self):
        self.root = {}
        self.end_symbol = "*"

# Words With Prefix
# Complete the search_level function. This recursive function collects all
# complete words starting from the current trie level. It takes the current
# dictionary level, the accumulated prefix so far, and the collection of words found.

class Trie:
    def search_level(self, current_level, current_prefix, words):
        #collections = words
        if self.end_symbol in current_level:
            words.append(current_prefix)
        for letter in sorted(current_level.keys()):
            if letter != self.end_symbol:
                self.search_level(current_level[letter], current_prefix + letter, words)
        return words

        if self.end_symbol in current_level:
            words.append(current_prefix)
        for letter in sorted(current_level.keys()):
            self.search_level(current_level[letter], current_prefix, letter, words)
                
        
        
        
        
            

    def words_with_prefix(self, prefix):
        match = []
        current = self.root
        for char in prefix:
            if char not in current:
                return []
            if char in current:
                current = current[char]
        return self.search_level(current,prefix,match)

    # don't touch below this line

    def __init__(self):
        self.root = {}
        self.end_symbol = "*"

    def add(self, word):
        current_level = self.root
        for letter in word:
            if letter not in current_level:
                current_level[letter] = {}
            current_level = current_level[letter]
        current_level[self.end_symbol] = True

