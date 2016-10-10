class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=nums[0]>0?nums[0]:0;
        int ret=nums[0];
        for (int i=1;i<nums.size();i++)
        {
            ret=max(ret,sum+nums[i]);
            if (nums[i]+sum>0)
                sum+=nums[i];
            else
                sum=0;
            
        }
        return ret;
    }
};