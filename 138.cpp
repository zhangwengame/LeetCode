/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *ohead) {
        if (!ohead)
            return nullptr;
        unordered_map<RandomListNode*,int> linkmap;
        RandomListNode* onow=ohead;
        
        int count=0;
        while (onow) {
            linkmap[onow]=count++;
            onow=onow->next;
        }
        RandomListNode* head=new RandomListNode(0);
        RandomListNode* now=head; 
        onow=ohead; 
        vector<RandomListNode*> pArray;
        while (onow) {
            now->label=onow->label;
            if (onow->next)
                now->next=new RandomListNode(0);
            pArray.push_back(now);
            now=now->next;
            onow=onow->next;
        }
        now=head;
        onow=ohead;
        while (onow) {
            if (onow->random) 
                now->random=pArray[linkmap[onow->random]];
            now=now->next;
            onow=onow->next;
        }
        return head;
    }
};