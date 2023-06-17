import sys


def rocks_jewelery() -> int:
    j = sys.stdin.readline().strip()
    s = sys.stdin.readline().strip()

    res = int()
    for ch in s:
        if ch in j:
            res += 1

    print(res)


rocks_jewelery()
