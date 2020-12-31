class Solution {
  public:
      int maxProfit(vector<int>& prices) {
        int maxPro = 0;
        int len = prices.size();
        int sum = 0;
        if(len < 2) return maxPro;
        for (int i=1;i<len;i++) {
            sum += prices[i]-prices[i-1];
            if (sum > maxPro) maxPro = sum;
            sum = sum > 0 ? sum: 0;
        }
        return maxPro;
    }
};