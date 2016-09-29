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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dumyHead= new ListNode(0);
        ListNode* last=dumyHead;
        while (l1||l2) {
            if (!l1||(l2!=nullptr&&l2->val<=l1->val)) {
                last->next=l2;
                last=l2;
                l2=l2->next;
                last->next=nullptr;
                //printf("%d\n",last->val);
            } else {
                last->next=l1;
                last=l1;
                l1=l1->next;
                last->next=nullptr;
                //printf("%d\n",last->val);
            }
        }
        return dumyHead->next;
    }
};