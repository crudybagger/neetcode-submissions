class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> front(nums.size() + 1, 1);
        vector<int> back(nums.size() + 1, 1);
        for(int i = 0; i < nums.size(); i++) {
            front[i+1] = front[i] * nums[i];
        }
        for(int i = nums.size()-1; i >= 0; i--) {
            back[i] = back[i+1]*nums[i];
        }
        vector<int> ans(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            ans[i] = front[i]*back[i+1];
        }
        return ans;
    }
};
