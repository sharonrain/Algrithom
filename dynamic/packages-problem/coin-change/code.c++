class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0 || coins.size() == 0) return 0;
        vector<int> dp(amount+1);
        for (auto coin: coins) {
            for (int i = coin; i<=amount; i++) {
                if (i == coin) {
                    dp[i] = 1;
                } else if (dp[i] == 0 && dp[i-coin] != 0) {
                    dp[i] = dp[i-coin]+1;
                } else if (dp[i-coin] != 0) {
                    dp[i] = min(dp[i], dp[i-coin] + 1);
                }
            }
        }
        return dp[amount] == 0 ? -1 : dp[amount];
    }
};

// dp[i][j] = max(dp[i-1][j], dp[i-1][j-w] + v)
// dp[j] = max(dp[j], dp[j-w] + v)