class Solution {
  public:
      vector<int> topKFrequent(vector<int>& nums, int k) {
          int len = nums.size();
          unordered_map<int, int> frequencyForNums;
          vector<vector<int>> cnts2(len+1, vector<int>());
          vector<int> res;

          for (int i = 0; i < nums.size(); i++) {
            frequencyForNums[nums[i]]++;
          }

          for (auto i:frequencyForNums)
            cnts2[i.second].push_back(i.first);

          for (int j=len; j>=0;--j)
            for (auto num: cnts2[j]) {
              res.push_back(num);
              if(!(--k)) return res;
            }
          return res;
      }
};