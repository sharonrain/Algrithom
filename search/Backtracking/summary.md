## Backtracking

1. in case of duplicate use of the same data: sort data, and use startIndex, or use visited array.
2. data can be used for serveral times, use startIndex for next iteration
3. when the data itself have duplicate
   ```
   i != 0 && nums[i] == nums[i - 1] && !visited[i - 1]
   ```
4. for combination, it can be cut when
   1. with start index
   2. data <= target
5. when the ask limit the data number as well as the target, the end limitation should consider both.
6. subSet, the same use start index to reduce duplicate
7. sodoku:
   1. have three visit array
   ```
    vector<vector<bool>> rowsUsed(9, vector<bool>(10, false));
    vector<vector<bool>> colsUsed(9, vector<bool>(10, false));
    vector<vector<bool>> cubesUsed(9, vector<bool>(10, false));
   ```
   2. fill the visited array with the original data
   3. find the next can be filled place of '.' and then backtracking with 0-9
8. nQueens problem:
   1. have tree visit array
   ```
    vector<bool> colsUsed(n, false);
    vector<bool> diagonals45Used(2*n - 1, false);
    vector<bool> diagonals135Used(2*n - 1, false);
   ```
   2. backtracking with [0, col]
   3. end condition is the row == n
