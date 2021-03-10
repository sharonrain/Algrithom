class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      vector<vector<int>> subsets;
      vector<int> subsetList;
      vector<bool> visited(nums.size(), false);
      for (int size = 0; size <= nums.size(); size++) {
        backtraking(0, subsetList, subsets, visited, size, nums);
      }
      return subsets;
    }

    void backtraking(int start, vector<int>& subsetList, vector<vector<int>>& subsets, vector<bool> visited, int size, vector<int>& nums) {
      if (subsetList.size() == size) {
        subsets.push_back(subsetList);
        return;
      }
      for(int i=start;i<nums.size();i++) {
        if (i != 0 && nums[i] == nums[i-1] && !visited[i-1]) {
          continue;
        }
        subsetList.push_back(nums[i]);
        visited[i] = true;
        backtraking(i+1, subsetList, subsets, visited, size, nums);
        visited[i] = false;
        subsetList.pop_back(); ////
      }
    }
};