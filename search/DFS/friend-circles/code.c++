class Solution {
public:
    int n;
    int findCircleNum(vector<vector<int>>& isConnected) {
      n = isConnected.size();
      vector<bool> hasVisited(n, false);
      int circleNum = 0;
      for (int i=0;i<n;i++) {
          if (!hasVisited[i]) {
              dfs(isConnected, i, hasVisited);
              circleNum++;
          }
      }
      return circleNum;
    }

    void dfs(vector<vector<int>>& isConnected, int i, vector<bool>& hasVisited) {
        for (int k=0;k<n;k++) {
            if(isConnected[i][k] == 1 && !hasVisited[k]) {
                hasVisited[i] = true;
                dfs(isConnected, k, hasVisited);
            }
        }
    }
};