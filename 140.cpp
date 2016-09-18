class Solution {
public:
    void generateAns(vector<vector<int> > &f, vector<string> &ret,int n,string &s){
        list<pair<int,int> > st;
        if (f[n].size()==0)
            return;
        st.push_back(make_pair(n,0));
        while (!st.empty()) {
            if (st.back().first==0) {
                string tmp;
                int last=0;
                for (auto it=(++st.rbegin());it!=st.rend();it++) {
                    tmp=tmp+s.substr(last,it->first-last)+" ";
                    last=it->first;
                }
                tmp.pop_back();
                ret.push_back(tmp);
               // cout<<tmp<<endl;
                st.pop_back();
                while (!st.empty()&&st.back().second+1>=f[st.back().first].size())
                    st.pop_back();
                if (!st.empty())
                    st.back().second++;
            } else {
                int next=f[st.back().first][st.back().second];
                st.push_back(make_pair(next,0));
            }
        }
    }
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<vector<int> > f(s.length()+1,vector<int>(0));
        f[0]=vector<int>(1,0);
        for (int i=1;i<=s.length();i++){
            for (int j=0;j<i;j++){
                if (wordDict.find(s.substr(j,i-j))!=wordDict.end()) {
                    if (f[j].size()!=0)
                        f[i].push_back(j);
                }
            }
        }
        vector<string> ret;
        generateAns(f,ret,s.length(),s);
        return ret;
    }
};