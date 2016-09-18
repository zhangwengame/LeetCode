class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        int len=s.length();
        if (words.size()==0)
            return ret;
        if (len==0)
            return ret;
        int wordLen=words[0].length();
        if (wordLen==0)
            return ret;
        unordered_map<string,int> wordDict;
        unordered_map<string,int> tmpWordDict;
        for (int i=0;i<words.size();i++)
            wordDict[words[i]]++;
        for (int i=0;i<wordLen;i++) {
            int st=i;
            int count=0;
            tmpWordDict.clear();
            for (int j=i;j<=len-wordLen;j+=wordLen) {
                string now=s.substr(j,wordLen);
                //cout<<now<<endl;
                if (wordDict.find(now)!=wordDict.end()) {
                    tmpWordDict[now]++;
                    count++;
                   //printf("%d %d %d\n",st,j,count);
                    while (tmpWordDict[now]>wordDict[now]){
                         tmpWordDict[s.substr(st,wordLen)]--;
                         st+=wordLen;
                         count--;
                        // printf("%d %d %d\n",st,j,count);
                    }
                   
                } else {
                    tmpWordDict.clear();
                    st=j+wordLen;
                    count=0;
                }
                if (count==words.size()) {
                    ret.push_back(st);
                }
                
            }
        }
        return ret;
    }
};