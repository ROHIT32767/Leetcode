class MyStack {
public:
    queue<int> Q1,Q2;
    MyStack() {
    }
    
    void push(int x) {
        Q1.push(x);
    }
    
    int pop() {
        while(Q1.size()){
            Q2.push(Q1.front());
            Q1.pop();
        }
        int back = Q2.back();
        while(Q2.size()>1){
            Q1.push(Q2.front());
            Q2.pop();
        }
        Q2.pop();
        return back;
    }
    
    int top() {
        return Q1.back();
    }
    
    bool empty() {
        return Q1.size()==0 ? true:false;
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