class Solution {
  public:
      int maximumGain(string s, int x, int y, char a = 'a', char b = 'b') {
        if (x < y) {
            swap(x, y);
            swap(a, b);
        }
        string s1 = helper(s, a, b);
        string s2 = helper(s1, b, a);

        return (s.size() - s1.size())/2 * x + (s1.size() - s2.size())/2 *y;
    }

    string helper(string s, char a, char b) {
        string temp;
        for (char c: s) {
            if (!temp.empty() && c == b && temp.back()==a) {
                temp.pop_back();
            } else {
                temp.push_back(c);
            }
        }
        return temp;
    }
};