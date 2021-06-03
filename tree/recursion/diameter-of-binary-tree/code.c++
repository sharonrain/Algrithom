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
    int maxDepthInTree = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        depthTree(root);
        return maxDepthInTree - 1;
    }

    int depthTree(TreeNode* root) {
      if (root == NULL) {
        return 0;
      }
      int left = depthTree(root->left);
      int right = depthTree(root->right);
      maxDepthInTree = max(maxDepthInTree, left + right + 1);
      return max(left, right) + 1;
    }
};