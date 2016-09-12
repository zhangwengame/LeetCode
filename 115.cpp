//#include£¼cstdio>
#include<cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int> > dp(s.length() + 1, vector<int>(t.length() + 1, 0));  ;
        
        for (int i=0;i<s.length()+1;i++) dp[i][0]=1;
        for (int i=0;i<t.length()+1;i++) dp[0][i]=0;
        dp[0][0]=1;
        for (int i=1;i<s.length()+1;i++){
        	for (int j=1;j<t.length()+1;j++){
        		dp[i][j]=dp[i-1][j];
        		if (s[i-1]==t[j-1]){
        			dp[i][j]+=dp[i-1][j-1];
        		}
        	}
        }
      //  cout<<dp[1][1]<<"\n";
        return dp[s.length()][t.length()];
    }
};
int main(){
	Solution *s=new Solution();
	cout<<s->numDistinct("rabbbit","rabbit");

}
