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
    vector<int> inorderTraversal(TreeNode* root) {
      vector<int> res;
      if (root == NULL)
        return res;
      stack<TreeNode*> s;
      TreeNode* cur = root;

      while(cur || !s.empty()) {
        while(cur) {
          s.push(cur);
          cur = cur->left;
        }
        TreeNode* node = s.top();
        res.push_back(node->val);
        s.pop();
        cur = node->right;
      }
      return res;
    }
};