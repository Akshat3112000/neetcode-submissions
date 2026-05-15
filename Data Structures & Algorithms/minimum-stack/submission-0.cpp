class MinStack {
    stack<int> a,b;
public:
    MinStack() {
        a = b = stack<int>();
    }
    
    void push(int val) {
        a.push(val);
        if(b.empty()) b.push(val);
        else
        {
            b.push(min(b.top(),val));
        }
    }
    
    void pop() {
        a.pop();
        b.pop();
    }
    
    int top() {
        return a.top();
    }
    
    int getMin() {
        return b.top();
    }
};
