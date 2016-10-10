class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret=0;
        int n=nums.size();
        for (int i=0;i<n;i++)
            ret=ret^nums[i];
        return ret;
    }
};