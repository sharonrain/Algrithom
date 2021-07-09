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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }
        ListNode* pathA = headA;
        ListNode* pathB = headB;
        bool switchA = false;
        bool switchB = false;
        while (pathA != pathB) {
            while (pathA != NULL && pathB != NULL) {
                pathA = pathA->next;
                pathB = pathB->next;
                if (pathA == pathB) return pathA;
            }
            if (switchA && switchB) return NULL;
            if (pathA == NULL) { pathA = headB; switchA = true; }
            if (pathB == NULL) { pathB = headA; switchB = true; }
        }
        return pathA;
    }
};