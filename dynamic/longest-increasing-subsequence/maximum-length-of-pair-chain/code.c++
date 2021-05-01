class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b){return a[1] < b[1];});
        int tail = INT_MAX;
        int res = 0;
        for (auto pair: pairs) {
            if (tail < pair[0] || tail == INT_MAX) {
                res++;
                tail = pair[1];
            } else {
                tail = min(tail, pair[1]);
            }
        }
        return res;
    }
};