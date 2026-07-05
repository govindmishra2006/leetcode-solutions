class MyStack {
public:
    vector<int> arr;
    int topIndex;
    MyStack() {
        topIndex = -1;
    }
    
        void push(int x) {
        topIndex++;
        arr.push_back(x);
    }
    
    int pop() {
        if(topIndex == -1)
        {
            return -1;
        }
        else
        {
            int val = arr[topIndex];
            topIndex--;
            arr.pop_back();
            return val;

        }
  
    }
    
    int top() {
        if(topIndex == -1) return -1;
        return arr[topIndex];
    }
    
    bool empty() {
        return arr.empty();
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