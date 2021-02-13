class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> combinations;
        vector<int> combineList;
        sort(candidates.begin(), candidates.end());
        backtraking(combineList, combinations, candidates, target, 0);
        return combinations;
    }

    void backtraking(vector<int>& combineList, vector<vector<int>>& combinations, vector<int>& candidates, int target, int startIndex) {
      if (target==0) {
        combinations.push_back(combineList);
        return;
      }
      for(int i=startIndex;i<candidates.size();i++) {
        if (candidates[i] <= target) {
          combineList.push_back(candidates[i]);
          backtraking(combineList, combinations, candidates, target - candidates[i], i);
          combineList.pop_back();
        }
      }
    }
};