class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combinations;
        vector<int> combineList;
        backtraking(combineList, combinations, 1, k, n);
        return combinations;
    }

    void backtraking(vector<int>& combineList, vector<vector<int>>& combinations, int start, int k, int n) {
      if (k==0) {
        combinations.push_back(combineList);
        return;
      }

      for(int i=start;i<=n-k+1;i++) {
        combineList.push_back(i);
        backtraking(combineList, combinations, i+1, k-1, n);
        combineList.pop_back();
      }
    }
};