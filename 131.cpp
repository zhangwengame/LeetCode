class Solution {
public:
    void dfs(string &s,int pos,vector<vector<bool>> &isP,vector<int> &hisPos, vector<vector<string>> &ret) {
        if (pos==s.length()) {
            vector<string> list;
            int last=-1;
            for (int i=0;i<hisPos.size();i++) {
                list.push_back(s.substr(last+1,hisPos[i]-last));
                last=hisPos[i];
            } 
            ret.push_back(list);    
        }
        for (int i=pos;i<s.length();i++) 
            if (isP[pos][i]) {
                hisPos.push_back(i);
                dfs(s,i+1,isP,hisPos,ret);
                hisPos.pop_back();
            }
    }
    vector<vector<string>> partition(string s) {
        int len=s.length();
        vector<vector<string>> ret;
        vector<vector<bool> > isP(len,vector<bool>(len,false));
        vector<int> hisPos;
        for (int i=0;i<len;i++)
            for (int j=i;j<len;j++) {
                int half=(j-i+1)/2;
                isP[i][j]=true;
                for (int k=0;k<half;k++)
                    if (s[k+i]!=s[j-k]) {
                        isP[i][j]=false;
                        break;
                    }
            }
        dfs(s,0,isP,hisPos,ret);
        return ret;
    }
};