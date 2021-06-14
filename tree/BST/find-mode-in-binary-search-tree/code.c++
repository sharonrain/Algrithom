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
    int curCnt = 1;
    int maxCnt = 1;
    TreeNode* preNode;
    vector<int> findMode(TreeNode* root) {
      vector<int> res;
      inOrder(root, res);
      return res;
    }

    void inOrder(TreeNode* root, vector<int>& nums) {
      if (root == NULL)
        return;
      inOrder(root->left, nums);
      if (preNode != NULL)
        curCnt = (preNode->val == root->val ? ++curCnt : 1);
      if (curCnt > maxCnt) {
        maxCnt = curCnt;
        nums.clear();
        nums.push_back(root->val);
      } else if (curCnt == maxCnt) {
        nums.push_back(root->val);
      }
      preNode = root;
      inOrder(root->right, nums);
    }
};