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
    int leftValue = 0;
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
          TreeNode* top = q.front();
          leftValue = top->val;
          int cnt = q.size();
          while (cnt--) {
            q.pop();
            if (top->left) q.push(top->left);
            if (top->right) q.push(top->right);
            if (!q.empty())
              top = q.front();
          }
        }
        return leftValue;
    }
};