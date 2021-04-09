class NumArray {
private:
  vector<int> sums;
public:
    NumArray(vector<int>& nums) {
      if(nums.size() > 0) {
          sums.push_back(0);
      }
      for (int i=1;i<=nums.size();i++) {
        sums.push_back(sums[i-1] + nums[i-1]);
      }
    }

    int sumRange(int left, int right) {
      return sums[right+1] - sums[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */