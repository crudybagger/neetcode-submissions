class MinStack {
public:
    stack<pair<int,int>> st;

    MinStack() {
    }
    
    void push(int val) {
        if(st.size() == 0) {
            st.push({val, val});
            return;
        }
        st.push({val, min(val, st.top().second)});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
