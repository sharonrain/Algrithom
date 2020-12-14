class Solution {
public:
    string reverseVowels(string s) {
        char vowelMap[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        set<char> vowels(vowelMap, vowelMap + 10);
        int start = 0;
        int end = 0;
        while (start < end) {
          while (vowelMap.find(s[start]) == vowels.end() && start < end) {
            start++;
          }
          while(vowelMap.find(s[end]) == vowels.end() && start < end) {
            end--;
          }
          swap(s, start, end);
        }
        return s;
    }

    bool swap(string& s, int i, int j) {
      char temp = s[i];
      s[i] = s[j];
      s[j] = temp;
    }
};