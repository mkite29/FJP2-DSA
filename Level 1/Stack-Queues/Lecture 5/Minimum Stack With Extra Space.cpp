class MinStack {
public:
    
    stack<int> minStack;
    stack<int> mainStack;
    
    void push(int val) {
        
        if(mainStack.size() == 0){
            minStack.push(val);
            mainStack.push(val);
        }
        else{
           minStack.push(min(val,minStack.top()));
           mainStack.push(val); 
        }
    }
    
    void pop() {
        mainStack.pop();
        minStack.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
