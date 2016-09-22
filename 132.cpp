class Solution {
public:
    int minCut(string s) {
        int len=s.length();
        vector<vector<bool> > isP(len,vector<bool>(len,false));
        vector<int> f(len,numeric_limits<int>::max());
        cout<<1<<endl;
        for (int i=0;i<len;i++)
            isP[i][i]=true;
        for (int l=2;l<=len;l++)
            for (int i=0;i+l-1<len;i++) {
                int j=i+l-1;
                //cout<<i<<" "<<j<<endl;
                if (s[i]==s[j]&&(i==j-1||isP[i+1][j-1]))
                    isP[i][j]=true;
            }
        //cout<<isP[0][1]<<endl;   
        f[0]=0;
        for (int i=1;i<len;i++) {
            if (isP[0][i])
                f[i]=0;
            for (int j=0;j<i;j++) {
                if (f[j]!=numeric_limits<int>::max()&&isP[j+1][i]&&f[j]+1<f[i])
                    f[i]=f[j]+1;
            }
                
        }
            
        return f[len-1];
    }
};