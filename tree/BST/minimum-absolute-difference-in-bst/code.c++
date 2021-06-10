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
    int minDiff = INT_MAX;
    TreeNode* preNode;
    int getMinimumDifference(TreeNode* root) {
        inOrder(root);
        return minDiff;
    }

    void inOrder(TreeNode* root) {
      if (root == NULL)
        return;
      inOrder(root->left);
      if (preNode != NULL)
        minDiff = min(minDiff, root->val - preNode->val);
      preNode = root;
      inOrder(root->right);
    }
};