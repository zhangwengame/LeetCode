class Solution {
public:
    vector<string> letterCombinations(string digits) {
        deque<string> ret;
        if (digits.length()==0)
            return vector<string>(ret.begin(),ret.end());
        char dic[10][4]={
            {' ','-','-','-'},
            {'-','-','-','-'},
            {'a','b','c','-'},
            {'d','e','f','-'},
            {'g','h','i','-'},
            {'j','k','l','-'},
            {'m','n','o','-'},
            {'p','q','r','s'},
            {'t','u','v','-'},
            {'w','x','y','z'}
        };
        ret.push_back("");
        for (int i=0;i<digits.length();i++){
            int size=ret.size();
            for (int j=0;j<size;j++){
                string &tmp=ret[0];
                for (int k=0;k<4;k++)
                    if (dic[digits[i]-'0'][k]!='-')
                        ret.push_back(tmp+dic[digits[i]-'0'][k]);
                ret.pop_front();
            }
        }
        return vector<string>(ret.begin(),ret.end());
    }
};