class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int k=2;
        int n=prices.size();
        if (n<=1)
            return 0;
        vector<vector<int> > f(n,vector<int>(1+k*2,0));
        f[0][0]=0;
        f[0][1]=-prices[0];
        for (int i=2;i<1+k*2;i++)
            f[0][i]=numeric_limits<int>::min();
        for (int i=1;i<n;i++) {
            for (int j=0;j<k;j++) {
                f[i][1+2*j]=max(f[i-1][1+2*j],
                                f[i-1][1+2*j-1]==numeric_limits<int>::min()?
                                numeric_limits<int>::min():f[i-1][1+2*j-1]-prices[i]);
                f[i][1+2*j+1]=max(f[i-1][1+2*j+1],f[i-1][1+2*j]+prices[i]);
            }
        
        }
        
        int ret=0;
        for (int i=0;i<1+k*2;i++)
            ret=max(ret,f[n-1][i]);
        return ret;
    }
};