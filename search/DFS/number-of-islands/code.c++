class Solution {
private:
  vector<vector<int>> direction = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
  int m, n;
public:
    int numIslands(vector<vector<char>>& grid) {
      if (grid.size() == 0)
        return 0;
      int islandsNumber = 0;
      m = grid.size();
      n = grid[0].size();
      for (int i=0;i<m;i++)
        for(int j=0;j<n;j++)
          if (grid[i][j] != '0') {
            dfs(grid, i, j);
            islandsNumber++
          }
      return islandsNumber;
    }

    void dfs(vector<vector<char>>& grid, int i, int j) {
      if (i<0 || i>=m||j<0||j>=n||grid[i][j]=='0')
        return;
      grid[i][j] = '0';
      for (auto d: direction) {
        dfs(grid, i+d[0], j+d[1]);
      }
    }
};