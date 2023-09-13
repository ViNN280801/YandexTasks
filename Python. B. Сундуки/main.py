def are_all_chest_opened(cur_chest: int, visited=None) -> str:
    if (visited is None):
        visited = set()

    # Mark current chest as visited
    visited.add(cur_chest)

    # Iterating by keys in specified chest
    for key in keys[cur_chest]:
        if (key == 'EMPTY'):
            key = 0
        key_number = int(key)

        # If key number not in a set of the opened chests - add it
        if (key_number not in visited):
            are_all_chest_opened(key_number, visited)

    # If length of the 'opened_chest' list is equals to the count of the chest
    # it means that the all chests are opened
    if (len(visited) == N):
        return "true"
    else:
        return "false"


# Count of the chests
N = int(input())

# Array of the keys in the chests
keys = list()

# Adding keys into the chests
for _ in range(N):
    key = input().split()
    keys.append(key)

# Printing result
print(are_all_chest_opened(0))
