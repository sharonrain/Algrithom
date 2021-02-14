class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> combinations;
        vector<int> combineList;
        vector<bool> hasVisited(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        backtraking(combineList, combinations, candidates, hasVisited, target, 0);
        return combinations;
    }

    void backtraking(vector<int>& combineList, vector<vector<int>>& combinations, vector<int>& candidates, vector<bool>& hasVisited, int target, int startIndex) {
      if (target==0) {
        combinations.push_back(combineList);
        return;
      }
      for(int i=startIndex;i<candidates.size();i++) {
        if (candidates[i] <= target) {
          if (i != 0 && candidates[i] == candidates[i-1] && !hasVisited[i-1]) {
            continue;
          }
          combineList.push_back(candidates[i]);
          hasVisited[i] = true;
          backtraking(combineList, combinations, candidates, hasVisited, target - candidates[i], i+1);
          hasVisited[i] = false;
          combineList.pop_back();
        }
      }
    }
};