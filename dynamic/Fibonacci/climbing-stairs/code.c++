class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        int pre1 = 2, pre2 = 1, cur = 0;
        for (int i = 2; i<n; i++) {
            cur = pre1 + pre2;
            pre2 = pre1;
            pre1 = cur;
        }
        return cur;
    }
};