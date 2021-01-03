class Solution {
  public:
      int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int preSum = nums[0];
        int result = preSum;
        for (int i=1; i<nums.size();i++) {
          preSum = preSum > 0 ? preSum + nums[i] : nums[i];
          result = max(result, preSum);
        }
        return result;
      }
};