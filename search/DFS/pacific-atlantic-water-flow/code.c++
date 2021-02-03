class Solution {
private:
  vector<vector<int>> direction = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
  int m, n;
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
      vector<vector<int>> ret;
      if (matrix.size() == 0)
        return ret;
      m = matrix.size();
      n = matrix[0].size();
      vector<vector<bool>> canReachP(m, vector<bool>(n, false)), canReachA(m, vector<bool>(n, false));

      for (int i=0;i<m;i++) {
        dfs(matrix, canReachP, i, 0);
        dfs(matrix, canReachA, i, n-1);
      }

      for(int j=0;j<n;j++) {
        dfs(matrix, canReachP, 0, j);
        dfs(matrix, canReachA, m-1, j);
      }
      for (int i=0;i<m;i++)
        for(int j=0;j<n;j++)
          if (canReachP[i][j] && canReachA[i][j]) {
            ret.push_back(vector<int>{i, j});
          }
      return ret;
    }

    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& canReach, int i, int j) {
      if (canReach[i][j])
        return;
      canReach[i][j] = true;
      for (auto d: direction) {
        int nexti = i+d[0];
        int nextj = j+d[1];
        if (nexti<0 || nexti>=m||nextj<0||nextj>=n|| matrix[nexti][nextj] < matrix[i][j]) {
          continue;
        }
        dfs(matrix, canReach, nexti, nextj);
      }
    }
};