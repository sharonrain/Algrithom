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
    map<TreeNode*, int> cache;
    int rob(TreeNode* root) {
        if (root == NULL)
            return 0;
        if (cache.find(root) != cache.end())
            return cache[root];
        int val = root->val;
        if (root->left != NULL)
            val += rob(root->left->left) + rob(root->left->right);
        if (root->right != NULL)
            val += rob(root->right->left) + rob(root->right->right);
        int valRoot = rob(root->left) + rob(root->right);
        int res = max(val, valRoot);
        cache[root] = res;
        return res;
    }
};