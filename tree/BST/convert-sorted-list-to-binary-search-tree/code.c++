/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
      if (head == NULL) return NULL;
      if (head->next == NULL) return new TreeNode(head->val);
      ListNode* preMid = getPreMid(head);
      ListNode* mid = preMid->next;
      preMid->next = NULL;
      TreeNode* t = new TreeNode(mid->val);
      t->left = sortedListToBST(head);
      t->right = sortedListToBST(mid->next);
      return t;
    }

    ListNode* getPreMid(ListNode* head) {
      ListNode* slow = head;
      ListNode* pre = head;
      ListNode* fast = head;
      while(fast != NULL && fast->next != NULL) {
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
      }
      return pre;
    }
};