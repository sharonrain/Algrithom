class Solution {
public:
    int rob(vector<int>& nums) {
        int pre1 = 0, pre2 = 0;
        for (int i = 0; i<nums.size(); i++) {
            int cur = max(pre2 + nums[i], pre1);
            pre2 = pre1;
            pre1 = cur;
        }
        return pre1;
    }
};