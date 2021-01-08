class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
      int n = letters.size();
      if (n == 1) return letters[0];
      int l = 0, h = n -1;
      while(l<=h) {
          int mid = l + (h-l)/2;
          if (letters[mid] <= target)
            l = mid + 1;
          else
            h = mid - 1;
        }

        return l < n ? letters[l] : letters[0];
    }
};