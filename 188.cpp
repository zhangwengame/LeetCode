//O(nk)
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if (n<=1)
            return 0;
        if (k>=n/2+1){
            int ret=0;
            for (int i=1;i<n;i++)
                ret+=prices[i]>prices[i-1]?prices[i]-prices[i-1]:0;
            return ret;
        }
        vector<vector<int> > f(2,vector<int>(1+k*2,0));
        f[0][0]=0;
        f[0][1]=-prices[0];
        for (int i=2;i<1+k*2;i++)
            f[0][i]=numeric_limits<int>::min();
        for (int i=1;i<n;i++) {
            int now=i%2;
            int last=(i-1)%2;
            for (int j=0;j<k;j++) {
                f[now][1+2*j]=max(f[last][1+2*j],
                                f[last][1+2*j-1]==numeric_limits<int>::min()?
                                numeric_limits<int>::min():f[last][1+2*j-1]-prices[i]);
                f[now][1+2*j+1]=max(f[last][1+2*j+1],
                                f[last][1+2*j]==numeric_limits<int>::min()?
                                numeric_limits<int>::min():f[last][1+2*j]+prices[i]);
                //cout<<i<<" "<<f[now][1+2*j]<<" "<<f[now][1+2*j+1]<<endl;
            }
        
        }
        
        int ret=0;
        int now=(n-1)%2;
        for (int i=0;i<1+k*2;i++)
            ret=max(ret,f[now][i]);
        return ret;
    }
};