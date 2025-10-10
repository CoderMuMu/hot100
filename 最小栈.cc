#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    // 思路：用一个辅助栈来存储当前的最小值，栈内始终维护的都是当前的最小值，围绕这个关键点即可
    // 辅助栈的每个位置都记录了主栈对应位置及其以下所有元素的最小
    stack<int> stk,minStack;
    MinStack() {
        minStack.push(INT_MAX);
    }
    
    void push(int val) {
        int x = min(val,minStack.top());
        stk.push(val);
        minStack.push(x);
    }
    
    void pop() {
        stk.pop();
        minStack.pop();
    }
    
    int top() {
        return stk.top();
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

/**
    * Your MinStack object will be instantiated and called as such:
    * MinStack* obj = new MinStack();
    * obj->push(val);
    * obj->pop();
    * int param_3 = obj->top();
    * int param_4 = obj->getMin();
    */

int main() {
    MinStack *minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    cout << minStack->getMin() << endl;
    minStack->pop();
    cout << minStack->top() << endl;
    cout << minStack->getMin() << endl;
    return 0;
}