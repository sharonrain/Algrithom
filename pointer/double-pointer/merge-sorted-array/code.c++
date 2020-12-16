class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      if (nums2 == null) return nums1;

      int end = m + n -1;
      int end1 = m-1;
      int end2 = n - 1;

      while (end2 >= 0 && end1 >= 0) {
        nums1[end--] = nums1[end1] >= nums2[end2] ? nums1[end1--] : nums2[end2--];
      }

      while(end2 >= 0) {
        nums1[end--] = nums2[end2--];
      }
    }
};