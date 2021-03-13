class Solution {
public:
    vector<vector<string>> partition(string s) {
      vector<vector<string>> partitions;
      vector<string> tempPartition;
      doPalindrome(s, partitions, tempPartition);
      return partitions;
    }

    void doPalindrome(string s, vector<vector<string>>& partitions, vector<string>& tempPartition) {
      if (s.length() == 0) {
        partitions.push_back(tempPartition);
        return;
      }
      for (int i = 0; i< s.length(); i++) {
        if (isPalindrome(s, 0, i)) {
          tempPartition.push_back(s.substr(0, i+1));
          doPalindrome(s.substr(i+1), partitions, tempPartition);
          tempPartition.pop_back();
        }
      }
    }

    bool isPalindrome(string s, int begin, int end) {
      while(begin < end) {
        if (s[begin++] != s[end--]) {
          return false;
        }
      }
      return true;
    }
};