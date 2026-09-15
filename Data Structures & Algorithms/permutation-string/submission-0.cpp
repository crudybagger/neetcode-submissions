class Solution {
    // [1,2,3,4]
    // [1,2,3]
public:
    bool isSame(vector<int> f1, vector<int> f2) {
        for(int i = 0; i < f1.size(); i++) {
            if(f1[i] != f2[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int> f1(256,0), f2(256,0);

        for(char c : s1) f1[c - 'a']++;
        for(int i = 0; i < s1.size(); i++) f2[s2[i] - 'a']++;

        if(isSame(f1,f2)) return true;

        for(int i = s1.size(); i < s2.size(); i++) {
            f2[s2[i] - 'a']++;
            f2[s2[i-s1.size()] - 'a']--;
            
            if(isSame(f1,f2)) return true;
        }
        return false;
    }
};
