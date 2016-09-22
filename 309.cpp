class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if (n==0)
            return 0;
        vector<vector<int> > f(n,vector<int>(3,0));
        f[0][0]=0;
        f[0][1]=-prices[0];
        f[0][2]=numeric_limits<int>::min();
        for (int i=1;i<n;i++) {
            f[i][0]=max(f[i-1][0],f[i-1][2]);
            f[i][1]=max(f[i-1][0]-prices[i],f[i-1][1]);
            f[i][2]=f[i-1][1]+prices[i];
        }
        int ret=0;
        ret=max(f[n-1][0],f[n-1][1]);
        ret=max(ret,f[n-1][2]);
        return ret;
    }
};