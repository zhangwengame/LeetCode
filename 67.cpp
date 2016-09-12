#include<cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
string addBinary(string a, string b) {
        string ret;
        int i1=a.length()-1,i2=b.length()-1;
        int len=0;
        while (i1>=0||i2>=0){
        	int t1=0,t2=0;
        	if (i1>=0){
        		t1=a.at(i1)-'0';
        		i1--;
        	}
        	if (i2>=0){
        		t2=b.at(i2)-'0';
        		i2--;
        	}
    		int tmp=ret.at(len)-'0'+t1+t2;
    		if(tmp>=2||i1>=0||i2>=0){
    			ret=ret+(tmp>=2?'1':'0');
    		}
    		tmp%=2;
    		ret.at(len)=(tmp==0)?'0':'1';
    		len++;
        }
        char t;
        for (int i=0;i<ret.length()/2;i++){
        	t=ret.at(i);
        	ret.at(i)=ret.at(ret.length()-1-i);
        	ret.at(ret.length()-1-i)=t;
        }
        return ret;
    }
  
};
int main(){
	Solution *s=new Solution();
	string ret=s->addBinary("1010","1011");
	cout<<ret<<endl;
}
