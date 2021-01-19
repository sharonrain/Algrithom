class Solution {
  public:
      int numSquares(int n) {
        vector<int> squres = generateSqures(n);
        queue<int> q;
        vector<bool> marked(n + 1, false);
        q.push(n);
        marked[n] = true;
        int level = 0;
        while(!q.empty()) {
          int size = q.size();
          level++;
          while(size-- > 0) {
            auto cur = q.front();
            q.pop();
            for (auto squre: squres) {
              int next = cur - squre;
              if (next < 0)
                break;
              else if (next == 0)
                return level;
              if (marked[next])
                continue;
              marked[next] = true;
              q.push(next);
            }
          }
        }
        return n;
      }

      vector<int> generateSqures(int n) {
        vector<int> squres;
        int squre = 1;
        int diff = 3;
        while(squre <= n) {
          squres.push_back(squre);
          squre += diff;
          diff += 2;
        }
        return squres;
      }
};