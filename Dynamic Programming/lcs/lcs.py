def lcs_memoization(i,j):
    if i == len1 or j == len2:
        return 0

    if dp[i][j] != -1:
        return dp[i][j]

    ans = 0

    if text1[i] == text2[j]:
        ans = 1 + lcs_memoization(i+1, j+1)
    else:
        val1 = lcs_memoization(i+1, j)
        val2 = lcs_memoization(i, j+1)
        ans = max(val1, val2)

    dp[i][j] = ans

    return dp[i][j]

        

def lcs_bottom_up():
    for i in range(1, len1 + 1):
        for j in range(1, len2 + 1):
            if text1[i-1] == text2[j-1]:
                dp[i][j] = 1 + dp[i-1][j-1]
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])

    return dp[-1][-1]


text1 = input("Enter First String: ")
text2 = input("Enter Second String: ")
dp = [[-1 for _ in range(len(text2)+1)] for _ in range(len(text1)+1)]
len1 = len(text1)
len2 = len(text2)
print(lcs_memoization(0,0))
dp = [[0 for _ in range(len(text2)+1)] for _ in range(len(text1)+1)]
print(lcs_bottom_up())