class Solution {
  public:
      string frequencySort(string s) {
          int len = s.length();
          unordered_map<char, int> frequencyForChars;
          vector<vector<char>> cnts(len+1, vector<char>());
          string res = "";

          for (int i = 0; i < len; i++) {
            frequencyForChars[s[i]]++;
          }

          for (auto i:frequencyForChars)
            cnts[i.second].push_back(i.first);

          for (int j=len; j>=0;--j)
            for (auto c: cnts[j]) {
              int k = j;
              while (k-- > 0)
                res += c;
            }
          return res;
      }
};