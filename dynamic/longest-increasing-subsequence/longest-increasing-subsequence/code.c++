class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len, 0);
        for (int i= 0; i<len;i++) {
            int maxCurrent = 1;
            for (int j=0;j<i;j++) {
                if (nums[i] > nums[j]) {
                    maxCurrent = max(maxCurrent, dp[j] + 1);
                }
            }
            dp[i] = maxCurrent;
        }
        int result = 0;
        for(auto res:dp) {
            result = max(res, result);
        }
        return result;
    }

    // the second ways of LIS, O(nlog(n))
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;

        int len = 0;
        for (auto num:nums) {
            int index = binarySearch(tails, len, num);
            if (tails.size() <= index) {
                tails.push_back(num);
            } else {
                tails[index] = num;
            }
            if (index == len) {
                len++;
            }
        }
        return len;
    }

    // use function binarySearch to decide whether to add array to tail
    int binarySearch(vector<int>& tails, int len, int num) {
        int l=0, h = len;
        while(l<h) {
            int mid = l+ (h-l)/2;
            if (tails[mid] == num) {
                return mid;
            } else if (tails[mid] > num) {
                h = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};