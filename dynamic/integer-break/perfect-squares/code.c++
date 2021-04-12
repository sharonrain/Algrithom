class Solution {
public:
    int numSquares(int n) {
        vector<int> squres = generateSqures(n);
        vector<int> dp(n+1, 0);
        for (int i=0;i<=n;i++) {
            int curMin = INT_MAX;
            for (auto squre: squres) {
                if (squre > i) {
                    break;
                }
                curMin = min(curMin, dp[i-squre] + 1);
            }
            dp[i] = curMin;
        }
        return dp[n];
    }

    vector<int> generateSqures(int n) {
        vector<int> squres;
        int squre = 1;
        int diff = 3;
        while(squre <= n) {
          squres.push_back(squre);
          squre += diff;
          diff += 2;
        }
        return squres;
    }
};