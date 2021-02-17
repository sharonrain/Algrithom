class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> combinations;
        vector<int> combineList;
        backtraking(combineList, combinations, n, k, 1);
        return combinations;
    }

    void backtraking(vector<int>& combineList, vector<vector<int>>& combinations, int target, int nums, int start) {
      if (target==0 && nums == 0) {
        combinations.push_back(combineList);
        return;
      }
      if (target == 0 || nums == 0)
          return;
      for(int i=start;i<=9;i++) {
        if (i <= target) {
          combineList.push_back(i);
          backtraking(combineList, combinations, target - i, nums-1, i+1);
          combineList.pop_back();
        }
      }
    }
};