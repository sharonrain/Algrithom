class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> products(n, 1);
        int left = 1;
        for (int i=1; i<n;i++) {
            left *= nums[i-1];
            products[i] *= left;
        }
        int right = 1;
        for (int i = n-2; i>=0;i--) {
            right *=nums[i+1];
            products[i] *= right;
        }
        return products;
    }
};