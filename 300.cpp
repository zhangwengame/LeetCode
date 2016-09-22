class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tmpLine;
        for (int i=0;i<nums.size();i++) {
            auto it=lower_bound(tmpLine.begin(),tmpLine.end(),nums[i]);
            if (it==tmpLine.end())
                tmpLine.push_back(nums[i]);
            else
                *it=nums[i];
        }
        return tmpLine.size();
    }
};