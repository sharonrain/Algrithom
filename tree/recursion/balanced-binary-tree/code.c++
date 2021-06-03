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
    bool result = true;
    bool isBalanced(TreeNode* root) {
      if (root == NULL)
        return true;

        maxDepth(root);
        return result;
    }

    int maxDepth(TreeNode* root) {
      if (root == NULL) {
        return 0;
      }
      int leftLen = maxDepth(root->left);
      int rightLen = maxDepth(root->right);
      if (abs(leftLen - rightLen) > 1)
        result = false;
      return max(leftLen, rightLen) + 1;
    }
};