class MyStack {
    queue<int> store[2];
    int curr;
    
public:
    /** Initialize your data structure here. */
    MyStack() {
        curr = 0;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        int next = 1 - curr;
        store[next].push(x);
        while(!store[curr].empty()) {
            store[next].push(store[curr].front());
            store[curr].pop();
        }
        curr = next;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int value = store[curr].front();
        store[curr].pop();
        return value;
    }
    
    /** Get the top element. */
    int top() {
        return store[curr].front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return store[curr].empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */