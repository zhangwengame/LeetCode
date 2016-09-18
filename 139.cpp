class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        vector<bool> f(s.length()+1,false);
        f[0]=true;
        for (int i=1;i<=s.length();i++){
            for (int j=0;j<i;j++){
                if (wordDict.find(s.substr(j,i-j))!=wordDict.end()) {
                    if (f[j])
                        f[i]=f[j];
                }
            }
        }
        return f[s.length()];
    }
};