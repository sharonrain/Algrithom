class Solution {
  public:
      vector<int> partitionLabels(string S) {
        vector<int> lastIndexOfChar(26, 0);
        for (int i=0;i<S.length();i++) {
          lastIndexOfChar[S[i]-'a'] = i;
        }

        vector<int> result;
        int firstIndex = 0;
        while(firstIndex < S.length()) {
          int lastIndex = firstIndex;
          for (int i = firstIndex; i < S.length() && i <= lastIndex;i++) {
            int index = lastIndexOfChar[S[i] - 'a'];
            if (index > lastIndex) {
              lastIndex = index;
            }
          }
          result.push_back(lastIndex - firstIndex + 1);
          firstIndex = lastIndex + 1;
        }
        return result;
      }
};