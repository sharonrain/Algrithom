class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        for (int i=0; i< nums.size(); i++) {
          while(nums[i] != i+1 && nums[nums[i] - 1] != nums[i]) {
            swap(nums, i, nums[i] -1);
          }
        }
        for (int i=0;i<nums.size(); i++) {
          if (nums[i] != i+1) {
            return new int[] { nums[i], i+1 };
          }
        }
    }

    void swap(vector<int>& nums, int i, int j) {
      int temp = nums[i];
      nums[i] = nums[j];
      nums[j] = temp;
    }
};