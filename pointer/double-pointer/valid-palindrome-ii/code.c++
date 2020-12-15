class Solution {
  public:
      bool validPalindrome(string s) {
          int start = 0;
          int end = s.length() - 1;

          while(start < end) {
            if (s[start] == s[end]) {
              start++;
              end--;
              continue;
            } else {
              int newStart1 = start, newEnd1 = end - 1;
              int newStart2 = start + 1, newEnd2 = end;

              while (newStart1 < newEnd1 && s[newStart1] == s[newEnd1]) {
                newStart1++;
                newEnd1--;
              }

              while (newStart2 < newEnd2 && s[newStart2] == s[newEnd2]) {
                newStart2++;
                newEnd2--;
              }

              return newStart1 >= newEnd1 || newStart2 > = newEnd2;
            }
          }
          return true;
      }

      bool validPalindrome(string s) {
        int start = 0;
        int end = s.length() - 1;

        while(start < end && s[start] == s[end]) {
          start++;
          end--;
        }

        return start >= end || isPalindrome(s, start+1, end) || isPalindrome(s, start, end-1);
      }
      // more simplified method, test again
      bool isPalindrome(string s, int i, int j) {
        while (i < j && s[i] == s[j]) {
          i++;
          j--;
        }
        return i >= j;
      }
};