class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashM;
        for (int i=0;i<nums.size();i++) {
            int targetNum = target-nums[i];
            if (hashM.find(targetNum) != hashM.end()) {
                return vector<int>({hashM[targetNum], i});
            }
            hashM[nums[i]] = i;
        }
        return vector<int>();
    }
};