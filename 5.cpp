class Solution {
public:
    void genL(string &s,vector<int> &newL) {
        newL.push_back(256);
        if (s.length()==0) {
            newL.push_back(257);
            return;
        }
        for (int i=0;i<s.length();i++) {
            newL.push_back(258);
            newL.push_back(s[i]);
        }
        newL.push_back(258);
        newL.push_back(257);
    }
    string longestPalindrome(string s) {
        vector<int> newL;
        vector<int> f;
        genL(s,newL);
        int maxR=0;
        int maxid=0;
        int ansid=0;
        f.resize(newL.size(),1);
        for (int i=1;i<newL.size();i++) {
            if (maxR>i) {
                f[i]=min(maxR-i,f[i*2-maxid]);
            } else
                f[i]=1;
            while (newL[i-f[i]]==newL[i+f[i]])
                f[i]++;
            if (f[i]+i>maxR) {
                maxR=f[i]+i;
                maxid=i;
            }
            if (f[i]>f[ansid])
                ansid=i;
        }
        //printf("%d %d\n",ansid,f[ansid]);
        string ret;
        for (int i=ansid-f[ansid]+1;i<=ansid+f[ansid]-1;i++)
            if (newL[i]<=255)
                ret+=char(newL[i]);
        return ret;
    }
};