class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        for(int i : nums) st.insert(i);

        int ans = 0;
        for(int n : nums) { 
            // if n starts a sequence, count it's length
            if(st.find(n-1) == st.end()) {
                int len = 1, curr = n+1;
                while(st.find(curr) != st.end()) {
                    len++;
                    curr++;
                }
                ans = max(ans, len);
            }
        }
        return ans;
        
    }
};
