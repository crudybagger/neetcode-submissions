class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nextSmallerPos(n), prevSmallerPos(n);

        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if(!st.empty()) prevSmallerPos[i] = st.top();
            else prevSmallerPos[i] = -1;

            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if(!st.empty()) nextSmallerPos[i] = st.top();
            else nextSmallerPos[i] = n;

            st.push(i);
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, (nextSmallerPos[i] - prevSmallerPos[i] - 1)*heights[i]);
        }
        return ans;

    }
};


/*
====    ====            
====    ====            
====    ====            
====    ====        ====
====    ====        ====
====    ================
========================
*/
// for each point, find next smaller and before smaller
// calculate the width and the height will be min current for all in between

