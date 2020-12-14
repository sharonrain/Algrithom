class Solution {
  public:
      bool judgeSquareSum(int c) {
          int start = 0;
          int end = sqrt(c);

          while(start <= end) {
            int sumOfSquare = start * start + end * end;
            if (sumOfSquare == c) {
              return true;
            } else if (sumOfSquare > c) {
              end--;
            } else {
              start++;
            }
          }
          return false;
      }
};