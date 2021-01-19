class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
          return -1;
        }
        vector<vector<int>> direction = {{1, -1}, {1, 0}, {1, 1}, {0, -1}, {0, 1}, {-1, -1}, {-1, 0}, {-1, 1}};
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        int pathLength = 0;
        while(!q.empty()) {
          int size = q.size();
          pathLength++;
          while(size-- > 0) {
            auto cur = q.front();
            q.pop();
            int cr = cur.first, cc = cur.second;
            if (grid[cr][cc] == 1)
              continue;
            if (cr == m - 1 && cc == n - 1)
              return pathLength;
            grid[cr][cc] = 1;
            for (auto d: direction) {
              int nr = cr + d[0], nc = cc+ d[1];
              if (nr < 0 || nr>=m || nc<0||nc>=n)
                continue;
              q.push(make_pair(nr, nc));
            }
          }
        }
        return -1;
    }
};