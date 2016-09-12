
#include<cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

#include<cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(255,0);
        int l=0,r=0,maxlen=0,st=-1;
        if (s.length()==0)
            return 0;
        for (r=0;r<s.length();r++){
        	while (l<r&&hash[s.at(r)]>0){
        		hash[s.at(l)]--;
        		l++;
        	}
        	hash[s.at(r)]++;
        	if (r-l+1>maxlen){
        		maxlen=r-l+1;
        		st=l;
        	}
        }
        return maxlen;
    }
};
int main(){

	Solution *s=new Solution();
	int ret=s->lengthOfLongestSubstring("abcabc");


}

