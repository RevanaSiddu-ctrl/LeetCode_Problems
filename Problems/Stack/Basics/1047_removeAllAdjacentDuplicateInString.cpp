/*
-------------------------------------------------------
Problem: 1047. Remove All Adjacent Duplicates In String
Difficulty: Easy
Topic: Stack, String

Approach:
- Use a stack to keep track of the characters that remain
  after removing adjacent duplicates.

1. Traverse the string character by character.
2. If the stack is empty or the current character is different
   from the top of the stack, push it.
3. If the current character is the same as the top of the stack,
   pop the top because the two adjacent characters form a pair
   and must be removed.
4. After processing the entire string, the stack contains the
   remaining characters, but they are in reverse order because
   stack follows LIFO.
5. Pop the stack into a string and reverse the result to restore
   the original order.

Example:
s = "abbaca"

a → push
b → push
b → same as top → pop
a → same as top → pop
c → push
a → push

Remaining stack represents "ca", so reverse it to get "ac".

Time Complexity: O(n)
Space Complexity: O(n)
-------------------------------------------------------
*/

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string str;

        for(char x : s) {
            if(st.empty() || st.top() != x) {
                st.push(x);
            } else if(st.top() == x) {
                st.pop();
            }
        }

        while(!st.empty()) {
            str.push_back(st.top());
            st.pop();
        }

        reverse(str.begin(), str.end());

        return str;
    }
};