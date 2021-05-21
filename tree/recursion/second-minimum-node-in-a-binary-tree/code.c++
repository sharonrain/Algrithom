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
    int findSecondMinimumValue(TreeNode* root) {
        if (root == NULL)
            return -1;
        if (root->left == NULL && root->right == NULL)
            return -1;
        int leftVal = root->left->val;
        int rightVal = root->right->val;
        if (root->left->val == root->val) leftVal = findSecondMinimumValue(root->left);
        if (root->right->val == root->val) rightVal = findSecondMinimumValue(root->right);

        if (leftVal != -1 && rightVal != -1) {
            return min(leftVal, rightVal);
        } else if (leftVal != -1) {
            return leftVal;
        }
        return rightVal;

    }
};