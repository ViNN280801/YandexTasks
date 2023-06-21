def solution() -> int:
    inputStr = list(input().split())
    offers = int(inputStr[0])
    customers = int(inputStr[1])

    prices = list(input().split())
    amounts = list(input().split())

    for i in range(offers):
        prices[i] = int(prices[i])

    for i in range(customers):
        amounts[i] = int(amounts[i])

    prices.sort()
    amounts.sort(reverse=True)

    result = int()
    min__ = min(len(prices), len(amounts))

    for i in range(min__):
        benefit = amounts[i] - prices[i]
        if benefit > 0:
            result += benefit

    print(result)


solution()
