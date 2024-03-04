def knapsack_recursive(i,capacity):
    
    if i == n or capacity == 0:
        return 0
    if weights[i]>capacity:
       return knapsack_recursive(i+1,capacity)
    return max(value[i]+knapsack_recursive(i+1,capacity-weights[i]),knapsack_recursive(i+1,capacity))


def knapsack_memoization(i,capacity,memo):
    if i == n or capacity == 0:
        return 0
    if memo[i][capacity]!=-1:
        return memo[i][capacity]
    if weights[i]>capacity:
       memo[i][capacity] = knapsack_memoization(i+1,capacity,memo)
    else:
       memo[i][capacity] = max(value[i]+knapsack_memoization(i+1,capacity-weights[i],memo),knapsack_memoization(i+1,capacity,memo))

    return memo[i][capacity]

def knapsack_bottom_up():
    dp = [[0] * (capacity + 1) for _ in range(n+1)]
    for i in range(1,n+1):
        for j in range(1,capacity+1):
            if weights[i-1] > j:
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-weights[i-1]]+value[i-1])
    return dp[n][capacity]

    



weights = list(map(int,input("Enter the weights:").split()))
value = list(map(int,input("Enter the value:").split()))
capacity = int(input("Enter Capacity:"))
n = len(weights)
memo = [[-1] * (capacity + 1) for _ in range(n)]
print(knapsack_memoization(0,capacity,memo))
print(knapsack_recursive(0,capacity))
print(knapsack_bottom_up())