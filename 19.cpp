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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dumyHead=new ListNode(0);
        dumyHead->next=head;
        ListNode* fast=dumyHead;
        ListNode* slow=dumyHead;
        for (int i=0;i<n;i++) 
            fast=fast->next;
        while (fast->next!=nullptr) {
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return dumyHead->next;
    }
};