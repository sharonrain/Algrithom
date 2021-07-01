class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
      int m = matrix.size(), n = matrix[0].size();
      int l = matrix[0][0];
      int h = matrix[m-1][n-1];
      while(l <= h) {
        int mid = l + (h-l)/2;
        int cnt = 0;
        for (int i=0; i<m;i++) {
          for (int j=0;j<n&&matrix[i][j] <= mid; j++) {
            cnt++;
          }
        }
        if (cnt < k) l = mid +1;
        else h = mid-1;
      }
      return l;
    }
};