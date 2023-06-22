def solution():
    n, m, q = map(int, input().split())
    dc = [[1] * m for x in range(n)]  # изначально все включены
    dr = [0] * m  # накапливаем количество перезапусков
    for x in range(q):
        cmd, *a, = input().split()
        *a, = map(int, a)
        if cmd == 'RESET':
            i = a[0]
            dc[i - 1] = [1] * m
            dr[i - 1] += 1
        elif cmd == 'DISABLE':
            i, j = a
            dc[i - 1][j - 1] = 0
        elif cmd == 'GETMAX':
            print(max(range(n), key=lambda x: dr[x] * dc[x].count(1)) + 1)
        elif cmd == 'GETMIN':
            print(min(range(n), key=lambda x: dr[x] * dc[x].count(1)) + 1)


solution()
