class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 1) return 0;
        vector<int> greatestLeft(height.size(), 0), greatestRight(height.size(), 0);
        for(int i = 1; i < height.size(); i++) {
            greatestLeft[i] = max(height[i-1], greatestLeft[i-1]);
        }
        for(int i = height.size()-2; i >= 0; i--) {
            greatestRight[i] = max(height[i+1], greatestRight[i+1]);
        }

        int ans = 0;
        for(int i = 0; i < height.size(); i++) {
            int here = max(min(greatestLeft[i], greatestRight[i]) - height[i], 0);
            // cout<<here<<"\n";
            ans+=here;
        }
        return ans;
    }
};
