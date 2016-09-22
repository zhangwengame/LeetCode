class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length()==0||t.length()==0)
            return "";
        unordered_map<char,int> oriChar;
        unordered_map<char,int> windowMap;
        for (int i=0;i<t.length();i++)
            oriChar[t[i]]++;
        int setCount=oriChar.size();
        int l=0;
        int r=0;
        int newCount=0;
        int ans=numeric_limits<int>::max();
        int ansB=-1;
        for (r=0;r<s.length();r++) {
            windowMap[s[r]]++;
            if (oriChar[s[r]]==windowMap[s[r]]) 
                newCount++;
            while (newCount==setCount&&l<=r) {
                if (r-l+1<ans) {
                    ans=r-l+1;
                    ansB=l;
                }
                if (oriChar[s[l]]==windowMap[s[l]]) 
                    newCount--;
                windowMap[s[l]]--;
                l++;
            }
        }
        if (ansB==-1)
            return "";
        else
            return s.substr(ansB,ans);
    }
};