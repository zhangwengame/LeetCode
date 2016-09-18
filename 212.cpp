class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
       end=false;
       nextp=vector<TrieNode*>(26,false);
    };
    vector<TrieNode*> nextp;
    bool end;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* t=root;
        for (int i=0;i<word.length();i++) {
            if (t->nextp[word[i]-'a']!=nullptr)
                t=t->nextp[word[i]-'a'];
            else {
                t->nextp[word[i]-'a']=new TrieNode();
                 t=t->nextp[word[i]-'a'];
            }
        }
        t->end=true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* t=root;
        for (int i=0;i<word.length();i++) {
            if (t->nextp[word[i]-'a']!=nullptr)
                t=t->nextp[word[i]-'a'];
            else
                return false;
        }
        return t->end;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
         TrieNode* t=root;
         for (int i=0;i<prefix.length();i++) {
            if (t->nextp[prefix[i]-'a']!=nullptr)
                t=t->nextp[prefix[i]-'a'];
            else
                return false;
        }
       return true;
    }

private:
    TrieNode* root;
};

class Solution {
public:

    void dfs(int i,int j,vector<vector<bool> > &flag, vector<vector<char>>& board, Trie &tree,set<string>& strSet,string now) {
        now=now+board[i][j];
        if (!tree.startsWith(now))
            return; 
        if (tree.search(now))
            strSet.insert(now);
            
        int n=board.size();
        int m=board[0].size();
        flag[i][j]=true;
        if (i>0&&!flag[i-1][j]) 
            dfs(i-1,j,flag,board,tree,strSet,now);
        if (i<n-1&&!flag[i+1][j]) 
            dfs(i+1,j,flag,board,tree,strSet,now);
        if (j>0&&!flag[i][j-1]) 
            dfs(i,j-1,flag,board,tree,strSet,now);
        if (j<m-1&&!flag[i][j+1]) 
            dfs(i,j+1,flag,board,tree,strSet,now);
        flag[i][j]=false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie tree;
        vector<string> ret;
        set<string> tmp;
        for (int i=0;i<words.size();i++)
            tree.insert(words[i]);
            
        int n=board.size();
        int m=board[0].size();

        vector<vector<bool> > flag(n,vector<bool>(m,false));
       
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++) 
                dfs(i,j,flag,board,tree,tmp,"");

        for (auto it=tmp.begin();it!=tmp.end();it++)
            ret.push_back(*it);
        return ret;
    }
};