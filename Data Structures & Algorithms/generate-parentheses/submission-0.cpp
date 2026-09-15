class Solution {
public:
    vector<string> generate(int open, int close) {
        // if can't close any more, return empty
        if(close == 0) return {""};
        // if can't open, can only close
        if(open == 0) {
            vector<string> next = generate(open, close-1);
            vector<string> ans;
            for(string s : next) {
                ans.push_back(")" + s);
            }
            return ans;
        } 
        // else if(open >= close) {
            // otherwise can open or close
        vector<string> nextOpen = generate(open-1, close);

        vector<string> nextClose; 
        if(close > open) nextClose = generate(open, close-1);
        vector<string> ans;
        for(string s : nextOpen) {
            ans.push_back("(" + s);
        }
        for(string s : nextClose) {
            ans.push_back(")" + s);
        }
        return ans;
        // }
    }
    vector<string> generateParenthesis(int n) {
        return generate(n, n);
    }
};
