/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      if (root == p || root == q || root == NULL)
        return root;
      TreeNode* leftRes = lowestCommonAncestor(root->left, p, q);
      TreeNode* rightRes = lowestCommonAncestor(root->right, p, q);

      if (leftRes && rightRes)
        return root;
      else if (leftRes == NULL)
        return rightRes;
      else
        return leftRes;
    }
};