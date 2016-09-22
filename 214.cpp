class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.length()==0)
            return "";
        string oriS=s;
        string ret=s;
        int len=s.length();

        for (int i=0;i<len;i++)
            s+=s[len-1-i];
        vector<int> next(s.length()+1,0);
        next[0]=0;
        next[1]=0;
        int last=0;
        for (int i=1;i<s.length();i++) {
            if (i==len)
                last=0;
            while (last>0&&s[last]!=s[i]) last=next[last];
            if (s[last]==s[i]) 
                last++;
            next[i+1]=last;
        }
        int maxPrePaliLen=next[s.length()];

        
        if (maxPrePaliLen>len)
            maxPrePaliLen=len;
        for (int i=maxPrePaliLen;i<len;i++)
            ret=s[i]+ret;
        return ret;
    }
};