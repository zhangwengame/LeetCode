class Solution {
public:
    void generate(unordered_set<string> &nextWordFrontier, const string &_nowS, unordered_set<string> &beginSet,
            unordered_set<string> &dic) {
                string nowS=_nowS;
                for (int i=0;i<nowS.length();i++){
                    char c=nowS[i];
                    for (int j='a';j<='z';j++)
                        if (j!=c){
                           nowS[i]=j;
                           if (dic.count(nowS)>0&&beginSet.count(nowS)==0) 
                                nextWordFrontier.insert(nowS);    
                           nowS[i]=c;
                        }
                }
            }
    void genPath(unordered_map<string, vector<string>> &answerTree,vector<string> &path, 
                const string& begin, const string &now,
                vector<vector<string>> &ret) {
                path.push_back(now);
                if (now==begin){
                    ret.push_back(path);
                    reverse(ret.back().begin(),ret.back().end());
                }
                else for (const string & s:answerTree[now]) {
                    genPath(answerTree,path,begin,s,ret);
                }        
                path.pop_back();
            }
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
            unordered_set<string> beginSet;
            unordered_set<string> endSet;
            unordered_map<string, vector<string>> answerTree;
            unordered_set<string> beginFrontier;
            unordered_set<string> endFrontier;
            unordered_set<string> nextFrontier;
            wordList.insert(beginWord);
            wordList.insert(endWord);
            beginSet.insert(beginWord);
            endSet.insert(endWord);
            beginFrontier.insert(beginWord);
            endFrontier.insert(endWord);
            bool found=false;
            bool direction=true;
            while (!found&&(!beginFrontier.empty()||!endFrontier.empty())) {
                if ((beginSet.size()>endSet.size()&&!endFrontier.empty())||beginFrontier.empty()) {
                    swap(beginSet,endSet);
                    swap(beginFrontier,endFrontier);
                    direction=!direction;
                }
                nextFrontier.clear();
                for (auto ite=beginSet.begin();ite!=beginSet.end();ite++) {
                    unordered_set<string> extendedSet;
                    generate(extendedSet,*ite,beginSet,wordList);
                    for (const string &s:extendedSet ){
                        if (endSet.count(s)>0) 
                            found=true;
                        if (direction)
                            answerTree[s].push_back(*ite);
                        else
                            answerTree[*ite].push_back(s);
                        nextFrontier.insert(s);
                    }
                }
                for (const string &s:nextFrontier) 
                    beginSet.insert(s);
                swap(beginFrontier,nextFrontier);
            }
            vector<vector<string>> ret;
            if (found){
                vector<string> path;
                genPath(answerTree, path ,beginWord,endWord,ret);
            }
            return ret;
        }
    
};