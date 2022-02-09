class MinStack {
public:
    long long int minVal = INT_MAX;
    stack<long long int> mainStack;
    
    void push(int val) {
        
        if(mainStack.size() == 0){
            mainStack.push(val);
            minVal = (long long)val;
        }
        
        else if(val < minVal){
                //encrypt kerke bhejna hai
                //and minValue ko update kerna hai
            mainStack.push((long long)2*val - minVal);
            minVal = (long long)val;
        }
            
        else
            mainStack.push(val);
        
    }
    
    
    
    void pop(){
        if(mainStack.size() == 0)return;
        
        if(mainStack.top() < minVal){
            //iska matlab value to hai ho encrypted  hai to usko decrypted 
            //kerna hai
            
            minVal = (long long )2*minVal - mainStack.top();
            mainStack.pop();
        }
        
        else
            mainStack.pop();
        
    }
    
    int top() {
        
        if(mainStack.size() == 0)return -1;
        
        if(mainStack.top() < minVal)
            return (long long)minVal;    
    
        return mainStack.top();
    }
    
    int getMin() {
        return minVal;
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
