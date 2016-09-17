class Solution {
public:
    bool isMatch(string s, string p) {
        int si=0;
        int pi=0;
        int n=s.length();
        int m=p.length();
        int markp=-1;
        int marks=-1;
        if (m==0 && n!=0)
            return false;
        while (si<n) {
            if (s[si]==p[pi]||p[pi]=='?') {
                si++;
                pi++;
            } else if (p[pi]=='*') {
                markp=pi;
                marks=si;
                pi++;
            } else {
                if (markp!=-1) {
                    pi=markp+1;
                    marks++;
                    si=marks;
                } else
                    return false;
            }
            if (pi==m) 
                if (si==n)
                    return true;
                else {
                   if (markp!=-1) {
                        pi=markp+1;
                        marks++;
                        si=marks;
                    } else
                        return false;
                }
                    
            
        }
        for (;pi<m;pi++)
            if (p[pi]!='*')
                return false;
        return true;
    }
};