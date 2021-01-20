class Solution {
private:
  vector<vector<int>> direction = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
  int m, n;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
      if (grid.size() == 0)
        return 0;
      m = grid.size();
      n = grid[0].size();
      int maxArea = 0;
      for (int i=0;i<m;i++)
        for(int j=0;j<n;j++)
          maxArea = max(maxArea, dfs(grid, i, j));
      return maxArea;
    }

    int dfs(vector<vector<int>>& grid, int i, int j) {
      if (i<0 || i>=m||j<0||j>=n||grid[i][j]==0)
        return 0;
      grid[i][j] = 0;
      int area = 1;
      for (auto d: direction) {
        area += dfs(grid, i+d[0], j+d[1]);
      }
      return area;
    }
};