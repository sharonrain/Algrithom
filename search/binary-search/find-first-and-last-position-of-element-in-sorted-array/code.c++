class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      int first = findFirst(nums, target);
      int last = findFirst(nums, target + 1) - 1;
      vector<int> results(2, -1);
      if (first == nums.size() || nums[first] != target) {
          return results;
      } else {
          results[0] = first;
          results[1] = nums[last + 1] == target ? last + 1 : max(first, last);
          return results;
      }
    }
    int findFirst(vector<int>& nums, int target) {
       int l = 0;
       int h = nums.size() -1;
       while (l < h) {
        int m = l + (h - l) / 2;
        if (nums[m] >= target) {
            h = m;
        } else {
            l = m + 1;
        }
      }
      return l;
    }
};