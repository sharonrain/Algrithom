class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
      vector<string> combinations;
      string temp = "";
      doCombination(temp, combinations, s, 0);
      return combinations;
    }

    void doCombination(string& tempS, vector<string>& combinations, string& s, int k) {
      if (k == 4 || s.length() == 0) {
        if (k == 4 && s.length() == 0) {
          combinations.push_back(tempS);
        }
        return;
      }
      for (int i = 0; i< s.length() && i<=2;i++) {
        if (i != 0 && s[0] == '0') {
          break;
        }

        string part = s.substr(0, i+1);
        if (atoi(part.c_str()) <= 255) {
          if (tempS.length() != 0)
            part = "." + part;
          tempS = tempS + part;
          string nextS = s.substr(i+1);
          doCombination(tempS, combinations, nextS, k + 1);
          tempS = tempS.substr(0, tempS.length() - part.length());
        }

      }
    }
};