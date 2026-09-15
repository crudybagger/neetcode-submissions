class Solution {
public:
    string process(string s) {
        string processed = "";
        for(char c : s) {
            // if(c >= 'a' && c <= 'z') processed += c;
            // if(c >= 'A' && c <= 'Z') processed += (c - 'A' + 'a');
            if(isalnum(c)) processed += tolower(c);
        }
        return processed;
    }
    bool isPalindrome(string s) {
        return isPalindromeProcessed(process(s));
    }
    bool isPalindromeProcessed(string s) {
        cout<<s;
        int l = 0, r = s.size()-1;
        while(l <= r) {
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
