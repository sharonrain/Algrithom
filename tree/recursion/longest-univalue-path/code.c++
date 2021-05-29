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
    int sum = 0;
    int longestUnivaluePath(TreeNode* root) {
        visitTree(root);

        return sum;
    }

    int visitTree(TreeNode* root) {
      if (root == NULL)
        return 0;
      int left = visitTree(root->left);
      int right = visitTree(root->right);
      int leftPath = root->left && root->left->val == root->val ? left + 1 : 0;
      int rightPath = root->right && root->right->val == root->val ? right + 1 : 0;

      sum = max(sum, rightPath + leftPath);
      return max(leftPath, rightPath);
    }
};