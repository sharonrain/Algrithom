class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
      long diff = 0;
      for(auto num: nums) {
        diff ^= num;
      }
      diff &= -diff;
      cout<<diff<<endl;
      vector<int> result(2, 0);
      for(auto num: nums) {
        if ((diff & num) == 0) {
          result[0]^=num;
        } else {
          result[1]^=num;
        }
      }
      return result;
    }
};