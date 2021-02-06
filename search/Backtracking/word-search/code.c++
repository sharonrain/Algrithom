class Solution {
public:
    vector<vector<int>> direction = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
    int m, n;
    bool exist(vector<vector<char>>& board, string word) {
      if (word.length() == 0) return true;
      if (board.size() == 0 || board[0].size() == 0) return false;
      m = board.size();
      n = board[0].size();
      vector<vector<bool>>visited(m, vector<bool>(n, false));
      for (int i=0;i<m;i++)
        for(int j=0;j<n;j++) {
          if (doSearch(board, i, j, word, 0, visited))
            return true;
        }
      return false;
    }

    bool doSearch(vector<vector<char>>& board, int i, int j, string word, int position, vector<vector<bool>>& visited) {
      if (position == word.length()) {
        return true;
      }
      if (i >= 0 && i < m && j>= 0 && j< n && board[i][j] == word[position] && !visited[i][j]) {
        visited[i][j] = true;
        for(auto d: direction) {
          if(doSearch(board, i+d[0], j+d[1], word, position + 1, visited))
            return true;
        }
        visited[i][j] = false;
      }
      return false;
    }
};