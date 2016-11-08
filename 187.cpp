class Solution {
public:
    int c2i(char c) {
        switch (c) {
            case 'A':return 0;
            case 'C':return 1;
            case 'G':return 2;
            case 'T':return 3;
        }
        return -1;
    }
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ret;
        unordered_set<int> hashSet;
        unordered_set<int> ansHashSet;
        if (s.length()<10)
            return ret;
        int hashKey=0;
        for (int i=0;i<10;i++) 
            hashKey=hashKey*4+c2i(s[i]);
        hashSet.insert(hashKey);
        int mo=1<<18;
        for (int i=10;i<s.length();i++) {
            hashKey%=mo;
            hashKey=hashKey*4+c2i(s[i]);
            if (hashSet.count(hashKey)!=0&&ansHashSet.count(hashKey)==0) {
                ret.push_back(s.substr(i-10+1,10));
                ansHashSet.insert(hashKey);
            }
            hashSet.insert(hashKey);
        }
        return ret;
    }
};