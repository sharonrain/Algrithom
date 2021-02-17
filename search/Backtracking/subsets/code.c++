class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>> subsets;
      vector<int> subsetList;
      for (int size = 0; size <= nums.size(); size++) {
        backtraking(0, subsetList, subsets, size, nums);
      }
      return subsets;
    }

    void backtraking(int start, vector<int>& subsetList, vector<vector<int>>& subsets, int size, vector<int>& nums) {
      if (subsetList.size() == size) {
        subsets.push_back(subsetList);
        return;
      }
      for(int i=start;i<nums.size();i++) {
        subsetList.push_back(nums[i]);
        backtraking(i+1, subsetList, subsets, size, nums);
        subsetList.pop_back();
      }
    }
};