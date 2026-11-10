class MinStack {
private:
    vector<int> custom_stack;
    vector<int> min_history;
public:
    MinStack() : custom_stack(), min_history() {
        
    }
    
    void push(int val) {
        custom_stack.push_back(val);
        if(min_history.size() == 0){
            min_history.push_back(val);
        }else{
            if(min_history[min_history.size()-1] >= val) min_history.push_back(val);
        }
    }
    
    void pop() {
        if(custom_stack.size()!=0){
            if(min_history.size() != 0){
              if(min_history[min_history.size()-1] == top()) min_history.pop_back();
            }
            custom_stack.pop_back();
        }
        
    }
    
    int top() {
        return custom_stack[custom_stack.size()-1];
    }
    
    int getMin() {
        return min_history[min_history.size()-1];
    }
};
