//#include£¼cstdio>
#include<cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<int,int> > st;
        int ans=0;
        for (int i=0;i<s.length();i++){
        	if ('('==s[i]){
        		st.push(make_pair(i,0));
        	}
			else{
        		if (st.empty()||1==st.top().second){
        			st.push(make_pair(i,1));
        		}
        		else{
        			st.pop();
        			if (st.empty())
        				ans=i+1>ans?i+1:ans;
        			else
        				ans=i-st.top().first>ans?i-st.top().first:ans;
        				
        		}
        	}
        }
        return ans;
    }
};
int main(){
	Solution *s=new Solution();
	cout<<s->longestValidParentheses("(()()");

}
