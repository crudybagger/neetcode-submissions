class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        for(int i : nums) st.insert(i);

        int ans = 0;
        for(int n : nums) { 
            // if n is not processed, and starts a sequence, count it's length
            if(st.find(n) != st.end() && st.find(n-1) == st.end()) {
                int len = 1, curr = n+1;
                st.erase(n);
                while(st.find(curr) != st.end()) {
                    //curr is processed, remove it from set
                    st.erase(curr);
                    len++;
                    curr++;
                }
                ans = max(ans, len);
            }
        }
        return ans;
    }
};
