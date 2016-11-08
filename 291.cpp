class Solution {
public:
    bool dfs(string& pattern,string& str,int p,int s,string charmap[],unordered_set<string>& usedstring) {
        for (;p<pattern.length();p++) {
            int len=charmap[pattern[p]].length();
            if (len==0)
                break;
            if (s+len>str.length()||str.compare(s, len, charmap[pattern[p]]) != 0) 
                return false; 
            s += len;
        }
        if (p == pattern.size()) 
            return s == str.size();
        for (int len=1;s+len<=str.length();len++) {
            string word = str.substr(s, len);
            //cout<<pattern[p]<<" "<<word<<endl;
            if (usedstring.count(word)!=0)
                continue;
            charmap[pattern[p]]=word;
            usedstring.insert(word);
            if(dfs(pattern,str,p+1,s+len,charmap,usedstring))
                return true;
            charmap[pattern[p]]="";
            usedstring.erase(word);
        }
        return false;
    }
    bool wordPatternMatch(string pattern, string str) {
        string charmap[256];
        unordered_set<string> usedstring;
        return dfs(pattern,str,0,0,charmap,usedstring);
    }
};