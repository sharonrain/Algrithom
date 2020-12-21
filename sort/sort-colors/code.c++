class Solution {
  public:
      void sortColors(vector<int>& nums) {
          int zero = -1;
          int one = 0;
          int two = nums.size();

          while(one < two) {
            if (nums[one] == 0) {
              swap(nums, ++zero, one++);
            } else if (nums[one] == 2) {
              swap(nums, --two, one);
            } else {
              ++one;
            }
          }
      }

      void swap(vector<int>& nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
      }
};