class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
      vector<vector<string>> result;
      vector<vector<char>>nQueens(n, vector<char>(n, '.'));
      vector<bool> colsUsed(n, false);
      vector<bool> diagonals45Used(2*n - 1, false);
      vector<bool> diagonals135Used(2*n - 1, false);

      backtracking(result, nQueens, colsUsed, diagonals45Used, diagonals135Used, 0, n);

      return result;
    }

    void backtracking(vector<vector<string>>& result, vector<vector<char>>& nQueens, vector<bool>& colsUsed, vector<bool>& diagonals45Used, vector<bool>& diagonals135Used, int row, int n) {
      if (row == n) {
        vector<string> list;
        for(auto item : nQueens) {
          string res = "";
          for(auto c: item) {
            res += c;
          }
          list.push_back(res);
        }
        result.push_back(list);
        return;
      }

      for (int col = 0; col < n; col++) {
        int diagonals45Idx = row + col;
        int diagonals135Idx = n-1 - (row-col);
        if (colsUsed[col] || diagonals45Used[diagonals45Idx] || diagonals135Used[diagonals135Idx]) {
          continue;
        }
        nQueens[row][col] = 'Q';
        colsUsed[col] = diagonals45Used[diagonals45Idx] = diagonals135Used[diagonals135Idx] = true;
        backtracking(result, nQueens, colsUsed, diagonals45Used, diagonals135Used, row + 1, n);
        colsUsed[col] = diagonals45Used[diagonals45Idx] = diagonals135Used[diagonals135Idx] = false;
        nQueens[row][col] = '.';
      }
    }
};