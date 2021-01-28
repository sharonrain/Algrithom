class Solution {
public:
    vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m, n;
    void solve(vector<vector<char>>& board) {
      if (board.size() == 0) {
          return;
      }
      m = board.size();
      n = board[0].size();

      for (int i = 0;i<m; i++) {
        dfs(board, i, 0);
        dfs(board, i, n-1);
      }

      for (int i = 0;i<n; i++) {
        dfs(board, 0, i);
        dfs(board, m-1, i);
      }

      for (int i = 0;i<m; i++)
        for (int j = 0;j<n; j++)
          if (board[i][j] == 'T')
            board[i][j] = 'O';
          else if (board[i][j] == 'O')
            board[i][j] = 'X';
    }

    void dfs(vector<vector<char>>& board, int r, int c) {
      if (r < 0 || r>=m || c<0||c>=n||board[r][c] != 'O') {
        return;
      }
      board[r][c] = 'T';
      for (auto d: direction)
        dfs(board, d[0] + r, d[1] + c);
    }
};