class Trie:
    def add(self, word):
        current = self.root
        for i in word:
            if i not in current:
                current[i] = {}
            current = current[i]

        current[self.end_symbol] = True


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


# Complete the advanced_find_matches method. It takes an entire document and a dictionary of character
# variations as input, and should return a set() of all the words in the trie that exist in the document
# as continuous substrings, even if the word had a variation character instead of the original.
    def advanced_find_matches(self, document, variations):
        matches = set()
        for i in range(len(document)):
            level = self.root
            for j in range(i, len(document)):
                ch = document[j]
                if ch in variations:
                    ch = variations[ch]
                if ch not in level:
                    break
                level = level[ch]
                if self.end_symbol in level:
                    matches.add(document[i : j + 1])
        return matches

# Complete the longest_common_prefix method. It returns
# the longest common prefix among the words in the trie.
    def longest_common_prefix(self):
        current = self.root
        prefix = ""
        while True:
            children = []
            for key in current.keys():
                if key == self.end_symbol:
                    break
                children.append(key)
            if len(children) == 1:
                prefix += children[0]
                current = current[children[0]]
            else:
                break
        return prefix

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

