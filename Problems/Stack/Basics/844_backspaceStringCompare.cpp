/*
-------------------------------------------------------
Problem: 844. Backspace String Compare
Difficulty: Easy
Topic: Stack, String

Approach:
- Use two stacks to simulate the effect of backspaces.
  - st1 processes string s.
  - st2 processes string t.

1. Traverse string s character by character.
2. If the character is '#':
   - If st1 is not empty, pop the previous character.
   - If st1 is empty, ignore '#'.
3. Otherwise, push the character into st1.
4. Do the same for string t using st2.
5. After processing both strings, compare st1 and st2.
6. If both stacks contain the same characters, the strings are
   equal after applying all backspaces.

Important:
- Never pop from an empty stack.
- '#' acts as a backspace, so it should never be pushed into
  the stack.

Example:
s = "ab#c"

a → push
b → push
# → pop b
c → push

Result = "ac"

Time Complexity: O(n + m)
Space Complexity: O(n + m)
-------------------------------------------------------
*/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1;
        stack<char> st2;

        for(char x : s) {
            if(!st1.empty() && x == '#') {
                st1.pop();
            } else if(x != '#') {
                st1.push(x);
            }
        }

        for(char x : t) {
            if(!st2.empty() && x == '#') {
                st2.pop();
            } else if(x != '#') {
                st2.push(x);
            }
        }

        if(st1 == st2) {
            return true;
        }

        return false;
    }
};