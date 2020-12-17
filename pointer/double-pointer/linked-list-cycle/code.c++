class Solution {
  public:
      bool hasCycle(ListNode *head) {
        if (head == null || head->next == null)
          return false;
        ListNode* oneStep = head;
        ListNode* twoSteps = head;
        while (twoSteps != null && twoSteps -> next != null) {
          oneStep = oneStep -> next;
          twoSteps = twoSteps -> next ->next;
          if (oneStep == twoSteps) {
            return true;
          }
        }
        return false;
      }
};