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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1 = buildStack(l1);
        stack<int> s2 = buildStack(l2);

        int carry = 0;
        ListNode* head = new ListNode(-1);
        while (!s1.empty() || !s2.empty() || carry != 0) {
            int num1 = 0, num2 = 0;
            if (!s1.empty()) {
                num1 = s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                num2 = s2.top();
                s2.pop();
            }
            int sum = (num1 + num2 + carry)%10;
            carry = (num1 + num2 + carry)/10;
            ListNode* tempNode = new ListNode(sum);
            tempNode->next = head->next;
            head->next = tempNode;
        }
        return head->next;
    }

    stack<int> buildStack(ListNode* head) {
        stack<int> res;
        while(head) {
            res.push(head->val);
            head= head->next;
        }
        return res;
    }
};