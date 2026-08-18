/*
-------------------------------------------------------
Problem: 155. Min Stack
Difficulty: Medium
Topic: Stack

Approach:
- Use two stacks:
  1. st    -> stores all the actual values.
  2. minst -> keeps track of the minimum values.

Push:
- Always push the value into st.
- If minst is empty or the new value is <= the current
  minimum, push it into minst as well.

Pop:
- If the top of st is the same as the top of minst, the
  current minimum is being removed, so pop from minst too.
- Then pop from st.

Top:
- Return st.top().

GetMin:
- The top of minst always contains the current minimum,
  so return minst.top() directly.

Why two stacks?
- A normal stack cannot access elements below the top.
- Searching the whole stack for the minimum would take O(n).
- minst keeps the current minimum ready at the top, allowing
  getMin() to work in O(1).

Important:
- Use <= while pushing into minst so duplicate minimum values
  are also tracked correctly.

Time Complexity:
- push()  -> O(1)
- pop()   -> O(1)
- top()   -> O(1)
- getMin()-> O(1)

Space Complexity: O(n)
-------------------------------------------------------
*/

class MinStack {
public:
    stack<int> st;
    stack<int> minst;

    MinStack() {
        
    }
    
    void push(int value) {
        st.push(value);

        if(minst.empty() || value <= minst.top()) {
            minst.push(value);
        }
    }
    
    void pop() {
        if(st.top() == minst.top())
            minst.pop();

        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};