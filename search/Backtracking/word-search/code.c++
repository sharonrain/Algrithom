class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<int> directions = {1, 0, -1, 0, 1};
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));

        function<bool(int, int, int)> func = [&](int i, int j, int k) {
            if (k == word.size()) {
                return true;
            }
            if (i < 0 || i >= m ||j < 0 || j >= n || board[i][j] != word[k] || visited[i][j])
                return false;
            visited[i][j] = true;
            for (int d = 0; d < 4; ++d) {
                if (func(i + directions[d], j + directions[d + 1], k + 1)) {
                    return true;
                }
            }
            visited[i][j] = false;
            return false;
        };

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (func(i, j, 0))
                    return true;
            }

        return false;
    }
};