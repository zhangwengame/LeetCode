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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        h=head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        random_device rd;
        default_random_engine generator(rd());  
        int ret;
        ret=h->val;
        int count=1;
        ListNode* tmp=h->next;
        while (tmp) {
            count++;
            uniform_int_distribution<int> dis(1,count);
            if (dis(generator)==count) {
                ret=tmp->val;
            }
            tmp=tmp->next;
        }
        return ret;
    }
private:
    ListNode* h;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */