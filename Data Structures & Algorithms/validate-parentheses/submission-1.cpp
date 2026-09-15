class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s) {
            if(c == '[' || c == '(' || c == '{') st.push(c);
            else {
                if(st.size() == 0) return false;
                else if(c == ']' && '[' == st.top()) st.pop();
                else if (c == ')' && '(' == st.top()) st.pop();
                else if (c == '}' && '{' == st.top()) st.pop();
                else return false;
            }
        }
        cout<<st.size()<<"\n";
        return (st.size() == 0);
    }
};
