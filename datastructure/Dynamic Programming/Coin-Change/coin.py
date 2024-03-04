def f(i,W):
    if  W < 0:
        return float('inf')
    if i == n:
        if W == 0:
            return 0
        return float('inf')

    if mem[i][W] != -1:
        return mem[i][W]

    res_1 = 1 + f(i, W - coins[i])
    res_2 = f(i + 1, W)

    mem[i][W] = min(res_1, res_2)

    return mem[i][W]
        



coins = list(map(int,input().split()))
amount = int(input())
n = len(coins)
mem = [[-1] * (amount+ 1) for _ in range(n + 1)]
result = f(0, amount)
print(result if result != float('inf') else -1)