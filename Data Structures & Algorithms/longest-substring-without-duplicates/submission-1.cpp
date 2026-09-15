class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        int ans = 0;
        set<char> st;
        while(l <= r && r < s.size()) {
            // if adding char at r causes duplicates, l++ untill no duplicates
            if(st.find(s[r]) != st.end()) {
                while(s[l] != s[r]) {
                    st.erase(s[l]);
                    l++;
                }

                l++;
            } else st.insert(s[r]);
            r++;
            // cout<<s.substr(l, r-l)<<"\n";
            ans = max(ans, r - l);
        }
        return ans;
    }
};
