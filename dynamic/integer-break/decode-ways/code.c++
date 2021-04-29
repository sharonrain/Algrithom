class Solution {
public:
    int numDecodings(string s) {
        if (s.length() == 0) {
            return 0;
        }

        vector<int> dp(s.length(), 0);
        dp[0] = s[0] == '0' ? 0 : 1;
        for (int i=1;i<s.length();i++) {
            if (s[i] != '0') {
                dp[i] += dp[i-1] ;
            }
            if (s[i-1] != '0' && atoi(s.substr(i-1,2).c_str()) <= 26) {
                dp[i] += (i>=2 ? dp[i-2] : 1);
            }
        }
        return dp[s.length() - 1];
    }
};