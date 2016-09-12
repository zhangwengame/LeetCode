
#include<cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	ListNode *ret=new ListNode(0),*now;
    	now=ret;
        while (l1!=NULL||l2!=NULL){
        	int t1=0,t2=0;
        	if (l1!=NULL)  {
        		t1=l1->val;
        		l1=l1->next;
        	}
        	if (l2!=NULL)  {
        		t2=l2->val;
        		l2=l2->next;
        	}
        	now->val+=t1+t2;
        	if (now->val>=10||l1!=NULL||l2!=NULL)
        		now->next=new ListNode(now->val/10);
        	now->val%=10;
        	now=now->next;
        }
        return ret;
    }
};/*
int main(){
	int a[]={150,24,79,50,88,345,3};
	vector<int> t(a,a+7);
	Solution *s=new Solution();
	vector<int> ret=s->twoSum(t,200);
	for (int i=0;i<ret.size();i++)
	cout<<ret[i]<<endl;

}*/
