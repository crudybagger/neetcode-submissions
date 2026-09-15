class Solution {
public:
    int replaceableChars(vector<int> freq) {
        int maxFreqChar, maxFreq = 0, curr = 0;
        for(int i = 0; i < 26; i++) {
            if(freq[i] > maxFreq) {
                maxFreqChar = i;
                maxFreq = freq[i];
            }
        }
        return maxFreqChar;
    }
    int characterReplacement(string s, int k) {
        // set<char> st;
        vector<int> freq(26, 0);
        int ans = 0;

        int l = 0, r = 0;
        while(l <= r && r < s.size()) {
            // add r
            freq[s[r++] - 'A']++;

            // if in current string you cannot replace k and make all same
            while(r - l > k + freq[replaceableChars(freq)]) freq[s[l++] - 'A']--;

            ans = max(ans, r-l);
        }
        return ans;
    }
};
