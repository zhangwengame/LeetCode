class Solution {
public:
    string convert(string s, int numRow) {
        if (s.length()==0)
            return "";
        if (numRow==1)
            return s;
        string ret;
        int st=0;
        for (;st<s.length();st+=(numRow*2-2))
            ret+=s[st];
        for (int i=1;i<numRow-1;i++){
            for (st=i;st<s.length();st+=(numRow*2-2)){
                ret+=s[st];
                if (st+(numRow*2-2*i-2)<s.length())
                    ret+=s[st+(numRow*2-2*i-2)];
            }
        }
        for (st=numRow-1;st<s.length();st+=(numRow*2-2))
            ret+=s[st];
        return ret;
    }
};