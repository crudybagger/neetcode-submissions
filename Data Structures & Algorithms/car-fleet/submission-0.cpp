class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<double> reachingTime(position.size(), 0);
        vector<pair<int,int>> pos;
        for(int i = 0; i < position.size(); i++) {
            pos.push_back({position[i], speed[i]});
        }
        sort(pos.begin(), pos.end());
        for(int i = 0; i < pos.size(); i++) {
            reachingTime[i] = target - pos[i].first;
            reachingTime[i] /= pos[i].second;

            cout<<reachingTime[i]<<" .\n";
        }

        stack<double> st;
        vector<double> nextSlowerCarTime(position.size(), -1);
        for(int i = position.size()-1; i >= 0; i--) {
            while(st.size() > 0 && st.top() < reachingTime[i]) st.pop();
            if(st.size() > 0) nextSlowerCarTime[i] = st.top();
            st.push(reachingTime[i]);
            cout<<nextSlowerCarTime[i]<<"\n";
        }

        // number of fleets are number of cars that don't have any car slower than it ahead of it
        int ans = 0;
        for(double i : nextSlowerCarTime) ans += (i == -1) ? 1 : 0;
        return ans;
    }
};
