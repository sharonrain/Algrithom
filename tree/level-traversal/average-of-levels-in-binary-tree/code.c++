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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<double> res;
        while(!q.empty()) {
          int cnt = q.size();
          int count = cnt;
          long sum = 0;
          while(cnt--) {
            TreeNode* top = q.front();
            q.pop();
            sum += top->val;
            if (top->left)
              q.push(top->left);
            if (top->right)
              q.push(top->right);
          }
          res.push_back(sum/(double)count);
        }
        return res;
    }
};