class Solution {
  public:
      int findKthLargest(vector<int>& nums, int k) {
        int index = nums.size() - k;
        return findKthLargestWithIndex(nums, 0, nums.size() - 1, index);
      }

      int findKthLargestWithIndex(vector<int>& nums, int startIndex, int endIndex, int index) {
        int pivot = findPivotIndex(nums, startIndex, endIndex);

        if (index == pivot) {
          return nums[pivot];
        }
        else if (index > pivot) {
          return findKthLargestWithIndex(nums, pivot + 1, endIndex, index);
        } else {
          return findKthLargestWithIndex(nums, startIndex, pivot - 1, index);
        }
      }

      int findPivotIndex(vector<int>& nums, int startIndex, int endIndex) {
        int pivot = nums[startIndex];

        while (startIndex < endIndex) {
          while(startIndex < endIndex && nums[endIndex] >= pivot) {
            endIndex--;
          }
          nums[startIndex] = nums[endIndex];
          while(startIndex < endIndex && pivot >= nums[startIndex]) {
            startIndex++;
          }
          nums[endIndex] = nums[startIndex];
        }

        nums[startIndex] = pivot;

        return startIndex;
      }
};