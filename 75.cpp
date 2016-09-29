class Solution {
public:
    void sortColors(vector<int>& nums) {
        int st=0;
        int ed=nums.size()-1;
        for (int i=0;i<=ed;i++) {
            while (nums[i]==2&&i<ed) {
                swap(nums[i],nums[ed]);
                ed--;
            }
            while (nums[i]==0&&i>st) {
                swap(nums[i],nums[st]);
                st++;
            }
        }
    }
};