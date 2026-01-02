# Nondeterministic polynomial time, NP, is the set of problems whose solutions
# can be verified in polynomial time, but not necessarily solved in polynomial time.

# Complete the tsp function by performing a brute-force search using the provided algorithm.
# The brute-force search will, unfortunately, take factorial time, O(n!), because you will need
# to try all possible paths and keep track of the shortest.

# The provided permutations() will give you all the possible permutations of a list. For example,
# permutations([0,1,2]) returns:

#Algorithm
# 1.    Use the permutations function to get the matrix of all possible paths through the given cities.
# Where the first path, [0, 1, 2] represents moving from city 0 -> city 1 -> city 2

# 2.  Iterate over each possible path (permutation)
# i. Sum the distances between each city in the path using the paths matrix to look up the distances
# ii. If the total distance of the path is less than the given dist return True

# 3.  If no short paths were found, return False

def tsp(cities, paths, dist):
    perms = permutations(cities)
    for perm in perms:
        total_dist = 0
        for i in range(1, len(perm)):
            total_dist += paths[perm[i - 1]][perm[i]]
        if total_dist < dist:
            return True
    return False


def permutations(arr):
    res = []
    res = helper(res, arr, len(arr))
    return res


def helper(res, arr, n):
    if n == 1:
        tmp = arr.copy()
        res.append(tmp)
    else:
        for i in range(n):
            res = helper(res, arr, n - 1)
            if n % 2 == 1:
                arr[n - 1], arr[i] = arr[i], arr[n - 1]
            else:
                arr[0], arr[n - 1] = arr[n - 1], arr[0]
    return res


paths = [
    [0, 12, 30], # list 0 shows the distance from city 0 to cities 0, 1 and 2
    [12, 0, 15], # list 1 shows the distance from city 1 to cities 0, 1 and 2
    [30, 15, 0], # list 2 shows the distance from city 2 to cities 0, 1 and 2
]

# all of the routes and their distances:

paths[0][1] # 12
paths[0][2] # 30
paths[1][2] # 15

# the shortest distance between all cities is from city 0 to city 1 to city 2, which is 27