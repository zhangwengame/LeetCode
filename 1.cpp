//#include｣ｼcstdio>
#include<cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
	struct pack{
		int index;
		int data;
		pack(int _index,int _data):index(_index),data(_data){
		}
		pack(){}
	};
	static bool cmp(const pack &a,const pack &b){
    	return a.data<b.data;
	}
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret(2);
        vector<pack> data(nums.size());
        for (int i=0;i<nums.size();i++)
       	{
       		data[i]=pack(i,nums[i]);
       	}
        sort(data.begin(),data.end(),cmp);
        int j=data.size()-1;
        for (int i=0;i<data.size()-1;i++){
        	if (j<=i) 
        		break;
        	while (j-1>i&&data[j].data+data[i].data>target) j--;
        	if (data[j].data+data[i].data==target)
        	{
        		ret[0]=data[i].index<=data[j].index?data[i].index:data[j].index;
        		ret[1]=data[i].index>=data[j].index?data[i].index:data[j].index;
        	}
        }
      
        return ret;
    }
};
int main(){
	int a[]={150,24,79,50,88,345,3};
	vector<int> t(a,a+7);
	Solution *s=new Solution();
	vector<int> ret=s->twoSum(t,200);
	for (int i=0;i<ret.size();i++)
	cout<<ret[i]<<endl;

}
