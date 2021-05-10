class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = computeSum(nums);
        if (sum < S || (sum + S) % 2 == 1) {
            return 0;
        }
        int W = (sum + S) / 2;
        vector<bool> dp(W + 1, false);
        dp[0]= true;
        for (auto num: nums) {
            for (int i=W; i>=num; i--)
                dp[i] = dp[i] || dp[i-num];
        }
        return dp[W];
    }

    int computeSum(vector<int>& nums) {
        int sum = 0;
        for (auto num: nums) {
            sum += num;
        }
        return sum;
    }
};