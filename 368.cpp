class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        if (n==0)
            return vector<int>();
        sort(nums.begin(),nums.end());
        vector<int> f(n);
        vector<int> last(n);
        for (int i=0;i<n;i++) {
            f[i]=1;
            last[i]=-1;
        }
            
     //   cout<<1<<endl;
        for (int i=1;i<n;i++)
            for (int j=0;j<i;j++)
                if (nums[i]%nums[j]==0) {
                    if (f[j]+1>f[i]) {
                        f[i]=f[j]+1;
                        last[i]=j;
                    }
                }
        int ans=0;
        int ansid;
        for (int i=0;i<n;i++)
            if (f[i]>ans) {
                ans=f[i];
                ansid=i;
            }
     //   cout<<ansid<<endl;
        vector<int> ret;
        while (ansid!=-1) {
            cout<<ansid<<endl;
            ret.push_back(nums[ansid]);
            ansid=last[ansid];
        }
        return ret;
        
    }
};