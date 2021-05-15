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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL)
          return res;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()) {
          TreeNode* cur =s.top();
          if ((!cur->left && !cur->right)||(pre == cur->left || pre == cur->right)) {
            res.push_back(cur->val);
            s.pop();
            pre = cur;
            continue;
          }
          if (top->left) s.push(top->left);
          if (top->right) s.push(top->right);
        }
        return res;
    }
};