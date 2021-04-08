class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, 0);
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (j==0) {
                    dp[j]=dp[j];
                } else if (i==0) {
                    dp[j] = dp[j-1];
                } else {
                    dp[j] = min(dp[j-1], dp[j]);
                }
                dp[j] += grid[i][j];
            }
        }
        return dp[n-1];
    }
};