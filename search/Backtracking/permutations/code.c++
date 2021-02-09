class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        vector<bool>visited(nums.size(), false);
        vector<int> permuteList;
        backtraking(permuteList, results, visited, nums);
        return results;
    }

    void backtraking(vector<int>& permuteList, vector<vector<int>>& permutes, vector<bool>& visited, vector<int>& nums) {
      if (permuteList.size() == nums.size()) {
        permutes.push_back(permuteList);
        return;
      }
      for(int i=0;i<visited.size();i++) {
        if (visited[i])
          continue;
        visited[i] = true;
        permuteList.push_back(nums[i]);
        backtraking(permuteList, permutes, visited, nums);
        permuteList.pop_back();
        visited[i] = false;
      }
    }
};