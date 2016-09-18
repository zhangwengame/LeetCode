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

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");