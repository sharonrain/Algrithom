class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> hashM;
        for(auto num: nums) {
          hashM[num] = 1;
        }
        for (auto num: nums) {
          forward(num, hashM);
        }

        return maxCount(hashM);
    }

    int forward(int num, unordered_map<int, int>& hashM) {
      if (hashM.find(num) == hashM.end()) {
        return 0;
      }
      if (hashM[num] > 1) {
        return hashM[num];
      }
      int cnt = forward(num+1, hashM) + 1;
      hashM[num] = cnt;
      return cnt;
    }

    int maxCount(unordered_map<int, int>& hashM) {
      int maxNum = 0;
      for (auto num: hashM) {
        maxNum = max(maxNum, num.second);
      }
      return maxNum;
    }
};