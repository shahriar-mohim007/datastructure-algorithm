#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;

    while (cin >> n) {
        vector<int> colors(n);
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; ++i) {
            cin >> colors[i];
        }

        for (int i = 0; i < n; ++i) {
            dp[i][i] = 0;
        }

        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;

                for (int k = i; k < j; ++k) {
                    int smoke = dp[i][k] + dp[k + 1][j] + colors[i] * colors[k + 1];
                    dp[i][j] = min(dp[i][j], smoke);
                }
            }
        }

        cout << dp[0][n - 1] << "\n";
    }

    return 0;
}
