class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        queue<string> l;
        l.push(beginWord);
        int ret=1;
        wordList.insert(endWord);
        while (!l.empty()){
            int size=l.size();
            for (int i=0;i<size;i++){
                string now=l.front();
                l.pop();
                if (now==endWord)
                    return ret;
                for (int j=0;j<now.length();j++){
                    int ori=now[j]-'a';
                    for (int k=0;k<26;k++){
                        if (k==ori)
                            continue;
                        now[j]='a'+k;
                        if (wordList.find(now)!=wordList.end()) {
                            l.push(now);
                            wordList.erase(now);
                        }
                    }
                    now[j]='a'+ori;
                }
            }
            ret++;
        }
        return 0;    
    }
};