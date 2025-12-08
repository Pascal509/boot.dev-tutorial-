from collections import defaultdict
from typing import List

strs = ["eat", "tea", "tan", "ate", "nat", "bat"]

class Solution:
    def groupAnagram(self, strs: List[str]) -> List[List[str]]:
        anagram_map = defaultdict(list)
        result = []

        for s in strs:
            sorted_s = tuple(sorted(s))
            anagram_map[sorted_s].append(s)

        for value in anagram_map.values():
            result.append(value)

        return result

sol = Solution()
print(sol.groupAnagram(strs))
