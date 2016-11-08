class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n==0)
            return 0;
        vector<vector<int> > f(2,vector<int>(n,0));
        f[0][0]=nums[0];
        f[1][0]=0;
        for (int i=1;i<n;i++){
            f[0][i]=f[1][i-1]+nums[i];
            f[1][i]=max(f[0][i-1],f[1][i-1]);
        }
        return max(f[0][n-1],f[1][n-1]);
    }
};