/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;
        ListNode* stepOne = head;
        ListNode* stepTwo = head;
        while(stepTwo!=NULL && stepTwo->next!=NULL) {
            stepOne=stepOne->next;
            stepTwo=stepTwo->next->next;
        }
        if (stepTwo != NULL)
            stepOne = stepOne->next;
        ListNode* reversedNode = reverseLink(stepOne);
        while(reversedNode!=NULL) {
            if(reversedNode->val != head->val)
                return false;
            reversedNode=reversedNode->next;
            head=head->next;
        }
        return true;
    }
    ListNode* reverseLink(ListNode* head) {
        ListNode* preNode = NULL;
        ListNode* curNode = head;
        while (curNode != NULL) {
            ListNode* nextNode = curNode->next;
            curNode->next = preNode;
            preNode = curNode;
            curNode = nextNode;
        }
        return preNode;
    }

};