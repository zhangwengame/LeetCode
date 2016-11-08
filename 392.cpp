class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.length();
        int m=t.length();
        if (n==0)
            return true;
        if (m==0)
            return false;
        int i=0;
        
        for (int j=0;j<m;j++)
            if (i<n&&s[i]==t[j])
                i++;
        if (i==n)
            return true;
        else
            return false;
    }
};