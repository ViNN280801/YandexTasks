def solution():
    n = int(input())
    probabilities = list()

    total = int()

    for i in range(n):
        abList = input().split()
        a = int(abList[0])
        b = int(abList[1])

        probabilities.append(a * b)
        total += probabilities[i]

    for i in range(n):
        print('{:.12f}'.format(float(probabilities[i]) / float(total)))


solution()
