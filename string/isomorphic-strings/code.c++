class Solution {
public:
    bool isIsomorphic(string s, string t) {
      vector<int> preIndexS(256, 0);
      vector<int> preIndexT(256, 0);

      for(int i=0;i<s.length(); i++) {
        if (preIndexS[s[i]] != preIndexT[t[i]]) {
          return false;
        }
        preIndexS[s[i]] = i+1;
        preIndexT[t[i]] = i+1;
      }
      return true;
    }
};