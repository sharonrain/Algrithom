class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
      vector<vector<bool>> rowsUsed(9, vector<bool>(10, false));
      vector<vector<bool>> colsUsed(9, vector<bool>(10, false));
      vector<vector<bool>> cubesUsed(9, vector<bool>(10, false));
      for (int i=0;i<9;i++)
        for (int j=0;j<9;j++) {
          if (board[i][j] == '.') {
            continue;
          }
          int num = board[i][j] - '0';
          rowsUsed[i][num] = true;
          colsUsed[j][num] = true;
          cubesUsed[cubeNum(i, j)][num] = true;
        }
      backtracking(board, rowsUsed, colsUsed, cubesUsed, 0, 0);
    }

    bool backtracking(vector<vector<char>>& board, vector<vector<bool>>& rowsUsed, vector<vector<bool>>& colsUsed, vector<vector<bool>>& cubesUsed, int row, int col) {
      while(row < 9 && board[row][col] != '.') {
        row = col == 8 ? row + 1 : row;
        col = col == 8 ? 0 : col + 1;
      }

      if (row == 9)
        return true;

      for (int num = 1; num <= 9; num++) {
        if (rowsUsed[row][num] || colsUsed[col][num] || cubesUsed[cubeNum(row, col)][num]) {
          continue;
        }
        rowsUsed[row][num] = colsUsed[col][num] = cubesUsed[cubeNum(row, col)][num] = true;
        board[row][col] = ('0' + num);
        if (backtracking(board, rowsUsed, colsUsed, cubesUsed, row, col))
          return true;
        board[row][col] = '.';
        rowsUsed[row][num] = colsUsed[col][num] = cubesUsed[cubeNum(row, col)][num] = false;
      }
      return false;
    }

    int cubeNum(int i, int j) {
      int r = i/3;
      int c = j/3;
      return r*3 + c; ////////
    }
};