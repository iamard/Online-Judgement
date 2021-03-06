class MyQueue {
    stack<int> s1;
    stack<int> s2;
    
    void makeQueue() {
        if (s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }
    
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        makeQueue();
        
        int value = s2.top();
        s2.pop();
        return value;
    }
    
    /** Get the front element. */
    int peek() {
        makeQueue();
        
        return s2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        makeQueue();
        
        return s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */