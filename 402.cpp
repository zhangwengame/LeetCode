class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> sta;
        for (int i=0;i<num.length();i++) {
  
            while (!sta.empty()&&num[i]<sta.top()&&k>0) {
                sta.pop();
                k--;
            }
            if (sta.size()==0&&num[i]=='0')
                continue;
            else
                sta.push(num[i]);
            
        }
        while (k>0&&!sta.empty()){
            sta.pop();
            k--;
        }
        string ret;
        while (!sta.empty()) {
            ret=ret+sta.top();
            sta.pop();
        }
        reverse(ret.begin(),ret.end());
        if (ret.length()==0)
            return "0";
        else
            return ret;
    }
};