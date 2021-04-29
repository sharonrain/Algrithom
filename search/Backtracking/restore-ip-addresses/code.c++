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
        if (k == 4 && s.length() == 0) { // for ip address, point 1 is to enhance the restriction for 4 length and no letter left
          combinations.push_back(tempS);
        }
        return;
      }
      for (int i = 0; i< s.length() && i<=2;i++) {
        if (i != 0 && s[0] == '0') { // point2: when the leading digit is 0, then it's wrong
          break;
        }

        string part = s.substr(0, i+1);
        if (atoi(part.c_str()) <= 255) { // check whether it's between [0, 255]
          if (tempS.length() != 0) // point 3, . is only added when it's not the first
            part = "." + part;
          tempS = tempS + part;
          string nextS = s.substr(i+1);
          doCombination(tempS, combinations, nextS, k + 1);
          tempS = tempS.substr(0, tempS.length() - part.length()); // point 4: restore, should remove part length
        }

      }
    }
};