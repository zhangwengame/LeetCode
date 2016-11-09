class MinStack {
private:
    long long minV;
    stack<long long > sta;
public:
    /** initialize your data structure here. */
    MinStack() {
        minV=0;
    }
    
    void push(int x) {
        if (sta.empty()){
            minV=x;
            sta.push(0);
        } else {
            sta.push((long long)x-minV);
            minV=min(minV,(long long)x);
        }
    }
    
    void pop() {
        if (sta.top()>=0)
            sta.pop();
        else {
            minV=minV-sta.top();
            sta.pop();
        }
    }
    
    int top() {
        if (sta.top()<0)
            return minV;
        else
            return minV+sta.top();
    }
    
    int getMin() {
        return minV;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */