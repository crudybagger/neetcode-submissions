class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int, int> mp;
        set<vector<int>> st;
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size(); i++) mp[nums[i]] = i;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < nums.size(); j++) {
                int target = 0 - nums[i] - nums[j];
                if(i != j && mp.find(target) != mp.end()) {
                    if(i != mp[target] && j != mp[target]) {
                        vector<int> v = {nums[i], nums[j], target};
                        sort(v.begin(), v.end());
                        st.insert(v);
                    }
                }
            }
        }

        for(auto v : st) ans.push_back(v);
        return ans;
    }
};
