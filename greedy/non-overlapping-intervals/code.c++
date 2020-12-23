class Solution {
  public:
      int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
          return 0;
        }

        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){ return a[1] < b[1]; });
        int cnt = 1;
        int end = intervals[0][1];

        for(int i=1; i< intervals.size(); i++) {
          if (intervals[i][0] < end) {
            continue;
          }
          end = intervals[i][1];
          cnt++;
        }
        return intervals.size() - cnt;
      }
};