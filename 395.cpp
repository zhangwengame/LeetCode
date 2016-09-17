class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.length()==0)
            return 0;
        int ret=0;
        queue<pair<int,int> > line;
        vector<vector<int> > count(s.length(),vector<int>(26,0));
        count[0][s[0]-'a']=1;
        for (int i=1;i<s.length();i++) {
            for (int j=0;j<26;j++)
                count[i][j]=count[i-1][j];
            count[i][s[i]-'a']=count[i][s[i]-'a']+1;
        }
            
                
        line.push(make_pair(0,s.length()-1));
        while (!line.empty()) {
            int st=line.front().first;
            int ed=line.front().second;
            //printf("%d %d\n",st,ed);
            line.pop();
            vector<int> flag(26,0);
            int bigFlag=0;
            for (int i=0;i<26;i++) {
                int tmp=st==0 ? 0:count[st-1][i];
                if (count[ed][i]-tmp>0&&count[ed][i]-tmp<k) {
                    flag[i]=1;
                    bigFlag=1;
                  //  printf("%d\n",i);
                }
                    
            }
            if (bigFlag==0) {
            //    printf("%d %d\n",st,ed);
                if (ed-st+1>ret)
                    ret=ed-st+1;
                continue;
            }
            int last=st-1;
            for (int i=st;i<=ed;i++) {
                if (flag[s[i]-'a']==1) {
                    if (i-1>=last+1)
                        line.push(make_pair(last+1,i-1));
                    last=i;
                }
            }
            if (last!=ed)
                line.push(make_pair(last+1,ed));
        }
        return ret;
    }
};