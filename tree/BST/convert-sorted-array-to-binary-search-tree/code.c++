/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      return toBST(nums, 0, nums.size() - 1);
    }

    TreeNode* toBST(vector<int>& nums, int startIndex, int endIndex) {
      if (startIndex > endIndex)
        return NULL;
      int midIndex = startIndex + (endIndex - startIndex) / 2;
      TreeNode* root = new TreeNode(nums[midIndex]);
      root->left = toBST(nums, startIndex, midIndex-1);
      root->right = toBST(nums, midIndex + 1, endIndex);

      return root;
    }
};