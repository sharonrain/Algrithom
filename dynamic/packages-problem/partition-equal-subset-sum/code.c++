class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = computeSum(nums);
        if (sum % 2 != 0) {
            return false;
        }
        int W = sum/2;
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