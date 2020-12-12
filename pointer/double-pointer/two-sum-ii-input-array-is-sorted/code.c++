class Solution {
  public:
      vector<int> twoSum(vector<int>& numbers, int target) {
        if (numbers == null)
          return null;

        int start = 0;
        int end = numbers.size();
        vector<int> results(2,0);

        while(start < end) {
          int sum = numbers[start] + numbers[end];
          if (sum == target) {
            return new int[] { start + 1, end + 1 };
          } else if (sum < target) {
            start++;
          } else {
            end--;
          }
        }
        return null;
      }
};