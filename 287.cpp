class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size()-1;
        int fast=nums[nums[n]-1]-1;
        int slow=nums[n]-1;
        while (fast!=slow) {
            fast=nums[nums[fast]-1]-1;
            slow=nums[slow]-1;
        }
        int third=n;
        while (third!=slow) {
            slow=nums[slow]-1;
            third=nums[third]-1;
        }
        return third+1;
    }
};