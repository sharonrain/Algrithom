class Solution {
public:
    vector<string> KEYS = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
      vector<string> combinations;
      if (digits.length() == 0)
        return combinations;
      string prefix = "";
      doCombination(prefix, combinations, digits);
      return combinations;
    }

    void doCombination(string& prefix, vector<string>& combinations, string digits) {
      if (prefix.length() == digits.length()) {
        combinations.push_back(prefix);
        return;
      }
      int curDigits = digits[prefix.length()] - '0';
      string letters = KEYS[curDigits];
      for(auto c: letters) {
        prefix.push_back(c);
        doCombination(prefix, combinations, digits);
        prefix.pop_back();
      }
    }
};