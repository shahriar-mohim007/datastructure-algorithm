def coin_change(i,amount):
    if amount<0:
       return -1
    if i==n:
        if amount==0:
            return 0
        return -1
    if memo[i][amount]!=-1:
       return memo[i][amount]
    


coins = list(map(int,input().split()))
amount = int(input())
n = len(coins)
memo = [[-1]*amount for _ in range(n)]
print(coin_change(0,amount))
