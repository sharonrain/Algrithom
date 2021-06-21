class Solution {
public:
    int count = 0;
    int countSubstrings(string s) {
        for(int i=0;i<s.length();i++) {
          extendSubStrings(s, i, i);
          extendSubStrings(s, i, i+1);
        }
        return count;
    }

    void extendSubStrings(string s, int startIndex, int endIndex) {
      while (startIndex >=0 && endIndex<s.length() && s[startIndex] == s[endIndex]) {
        startIndex--;
        endIndex++;
        count++;
      }
    }
};