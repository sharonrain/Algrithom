class Solution {
public:
    int rob(vector<int>& nums) {
      if (nums.size() == 0) {
        return 0;
      }
      int n = nums.size();
      if(n == 1) return nums[0];
      return max(rob(nums, 0, n-2), rob(nums, 1, n-1));
    }

    int rob(vector<int>& nums, int first, int last) {
        int pre1 = 0, pre2 = 0;
        for (int i = first; i<=last; i++) {
            int cur = max(pre2 + nums[i], pre1);
            pre2 = pre1;
            pre1 = cur;
        }
        return pre1;
    }
};