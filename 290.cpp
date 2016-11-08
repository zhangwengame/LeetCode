class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char,string> dica;
        unordered_map<string,char> dicb;
        str=str+' ';
        if (str.length()==0||pattern.length()==0)
            return false;
        int startPos=0;
        for (int i=0;i<pattern.length();i++) {
            int pos=str.find(' ',startPos);
            string word=str.substr(startPos,pos-startPos);
            startPos=pos+1;
            if (dica.find(pattern[i])==dica.end()&&dicb.find(word)==dicb.end()) {
                dica[pattern[i]]=word;
                dicb[word]=pattern[i];
            } else if (dica.find(pattern[i])==dica.end()||dicb.find(word)==dicb.end())
                return false;
            else if (dica[pattern[i]]!=word||dicb[word]!=pattern[i])
                return false;
        }
        if (startPos!=str.length())
            return false;        
        return true;
    }
};