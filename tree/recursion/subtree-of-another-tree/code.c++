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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL)
          return false;
        return isSubTreeWithCurrentNode(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isSubTreeWithCurrentNode(TreeNode* root, TreeNode* subRoot) {
      if (!subRoot && !root) {
        return true;
      }
      if (!root || !subRoot || root->val != subRoot->val)
        return false;
      return isSubTreeWithCurrentNode(root->left, subRoot->left) && isSubTreeWithCurrentNode(root->right, subRoot->right);
    }
};