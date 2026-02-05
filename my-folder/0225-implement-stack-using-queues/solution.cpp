class MyStack {
    queue<int>st1,st2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        st2.push(x);

        while(!st1.empty())
        {
            st2.push(st1.front());
            st1.pop();
        }

        swap(st1,st2);
    }
    
    int pop() {
        int topval = st1.front();
        st1.pop();
        return topval;
    }
    
    int top() {
        return st1.front();
    }
    
    bool empty() {
        if(st1.empty()) return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
