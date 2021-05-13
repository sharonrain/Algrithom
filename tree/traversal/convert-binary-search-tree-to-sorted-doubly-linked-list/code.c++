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
    TreeNode* pre;
    TreeNode* head;
    TreeNode* convertBinarySearchTreeToSortedDoublyLinkedList(TreeNode* root) {
      if (root == NULL)
        return NULL;
      inOrder(root);
      head->left = pre;
      pre->right = head;
    }

    void inOrder(TreeNode* cur) {
      if (cur == NULL)
        return;
      inOrder(cur->left);
      if (pre != NULL)
        pre->right = cur;
      else
        head = cur;
      cur->left = pre;
      pre = cur;
      inOrder(cur->right);
    }
};