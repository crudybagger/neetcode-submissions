class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        for(int i : nums) {
            freq[i]++;
        }
        vector<pair<int,int>> rev;
        for(auto it : freq) {
            rev.push_back({it.second, it.first});
        }
        sort(rev.begin(), rev.end());
        vector<int> ans;
        for(int i = 0; i < k; i++) {
            ans.push_back(rev[rev.size()-i-1].second);
        }
        return ans;
    }
};
