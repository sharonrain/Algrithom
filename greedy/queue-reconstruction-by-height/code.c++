class Solution {
  public:
      vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> result;
        if (people.size() == 0 || people[0].size() == 0) {
          return result;
        }

        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b){ return a[0] == b[0] ? (a[1] < b[1]) : (b[0] < a[0]); });

        for(auto p: people) {
          result.insert(result.begin() + p[1], p);
        }
        return result;
      }
};