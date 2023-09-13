from collections import Counter


def k_most_freq_elem(range: list, k: int) -> list:
    """ 
    Args:
        range: array of the elements.
        k: count of the most frequency elements.

    Returns:
      'k' most frequency elements in the array 'range' in ascending sorted form.
    """

    # 1. Creating 'Counter' obj, which counts the occurences in the array
    # 2. Sorting the list of the tuples by count in a descending order,
    # where each tuple contains element and its count
    return sorted(el for el, count in Counter(range).most_common(k))


# N - length of the array
# k - count of the most frequency elems in the array
N, k = map(int, input().split())

# Get array
arr = list(map(int, input().split()))

# Print the result separated by a space
print(' '.join(map(str, k_most_freq_elem(arr, k))))
