class MinStack {
public:
    stack<int> st;
    stack<int> minStack;

    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minStack.empty()){
            minStack.push(val);
        }else
            minStack.push(min(val,minStack.top()));
    }
    
    void pop() {
     if(!st.empty()){
        st.pop();
        minStack.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
