class MyQueue {
public:
    stack<int> S1,S2;
    MyQueue() {
        
    }
    
    void push(int x) {
        S1.push(x);
    }
    
    int pop() {
        while(S1.size()>1){
            S2.push(S1.top());
            S1.pop();
        }
        int front = S1.top();
        S1.pop();
        while(S2.size()){
            S1.push(S2.top());
            S2.pop();
        }
        return front;
    }
    
    int peek() {
        while(S1.size()>1){
            S2.push(S1.top());
            S1.pop();
        }
        int front = S1.top();
        S2.push(S1.top());
        S1.pop();
        while(S2.size()){
            S1.push(S2.top());
            S2.pop();
        }
        return front;
    }
    
    bool empty() {
        return S1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */