class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        for (int i=2;i<=n;i++) {
            for (int j=1; j<=i-1;j++) {
                // here max(j*dp[i-j], j*(i-j)) because compare the data of split with the whole number
                // max(dp[i], xxx) to compare the data wit previous iteration
                dp[i] = max(dp[i], max(j*dp[i-j], j*(i-j)));
            }
        }
        return dp[n];
    }
};