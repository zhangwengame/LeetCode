class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        set<int> wordLenSet;
        vector<vector<int> > ret;
        unordered_map<string,int> wordDic;
        for (int i=0;i<words.size();i++) {
            wordLenSet.insert(words[i].length());
            wordDic[words[i]]=i;
        }
        for (int i=0;i<words.size();i++){
            string t=words[i];
            reverse(t.begin(),t.end());
            if (wordDic.find(t)!=wordDic.end()&&wordDic[t]!=i)
                ret.push_back({i,wordDic[t]});
            int len=words[i].length();
            auto itNow=wordLenSet.find(len);
            string rev=words[i];
            reverse(rev.begin(),rev.end());
            for (auto it=wordLenSet.begin();it!=itNow;it++) {
                int addLen=*it;
                if (isValid(rev,addLen,len-addLen)&&wordDic.find(rev.substr(0,addLen))!=wordDic.end())//add on left
                    ret.push_back({wordDic[rev.substr(0,addLen)],i});
                if (isValid(rev,0,len-addLen)&&wordDic.find(rev.substr(len-addLen,addLen))!=wordDic.end())//add on right
                    ret.push_back({i,wordDic[rev.substr(len-addLen,addLen)]});
            }
        }
        return ret;
        
    }
    bool isValid(string &s,int st,int len) {
        int limit=len/2;
        for (int i=0;i<limit;i++)
            if (s[i+st]!=s[st+len-1-i])
                return false;
        return true;
    }
};