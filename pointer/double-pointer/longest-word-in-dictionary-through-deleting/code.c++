class Solution {
  public:
      string findLongestWord(string s, vector<string>& d) {
        string validWord = "";

        for(int i=0;i<d.size();i++) {
          if (d[i].length() < validWord.length() || ((d[i].length() == validWord.length() && validWord.compare(d[i]) < 0)))
            continue;
          if (isSubStr(s, word)) {
            validWord = word;
          }
        }

        return validWord;
      }

      bool isSubStr(string s, string w) {
        if (w.length() > s.length()) return false;

        int i=0;
        int m=0;
        while(i < s.length() && m < w.length()) {
          if (s[i] == w[m]) {
            m++;
          }
          i++;
        }

        return m == w.length();
      }
};