class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l < r) {
            if(nums[l] + nums[r] < target) l++;
            if(nums[l] + nums[r] > target) r--;
            if(nums[l] + nums[r] == target) return {l+1, r+1};
        }
        return {-1,-1};
    }
};
