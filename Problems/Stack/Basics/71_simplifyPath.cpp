/*
-------------------------------------------------------
Problem: 71. Simplify Path
Difficulty: Medium
Topic: Stack, String Parsing

Approach:
- Use a stack of strings to store valid directory names.
- Use `component` to build one directory name at a time.
- '/' acts as a separator between components.

Rules:
1. Normal directory name:
   - Push it into the stack.
2. ".":
   - Ignore it because it means the current directory.
3. "..":
   - Pop the top directory if the stack is not empty.
4. Empty component:
   - Ignore it. This handles consecutive '/' characters.
5. '/' is not stored in the stack because it is only a separator.

Important:
- `component` collects characters until '/' is found.
- When '/' is found, the completed component is processed first,
  and only then `component` is reset to "".
- The last component needs to be processed separately because
  the path may not end with '/'.
- The stack stores only directory names, not '/'.

Building the Answer:
- Stack follows LIFO, so directories come out in reverse order.
- Add each popped directory to the FRONT of `ans`:
      ans = "/" + st.top() + ans;

Example:
Input: /a/b/../c/./d

a  → push
b  → push
.. → pop b
c  → push
.  → ignore
d  → push

Final stack represents:
a → c → d

Answer:
"/a/c/d"

Time Complexity: O(n)
Space Complexity: O(n)
-------------------------------------------------------
*/

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string component;
        string ans;

        for(char c : path) {
            if(c == '/') {
                if(component == "..") {
                    if(!st.empty()) {
                        st.pop();
                    }
                }
                else if(component != "" && component != ".") {
                    st.push(component);
                }

                component = "";
            }
            else {
                component += c;
            }
        }

        if(component == "..") {
            if(!st.empty()) {
                st.pop();
            }
        }
        else if(component != "" && component != ".") {
            st.push(component);
        }

        while(!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }

        return ans.empty() ? "/" : ans;
    }
};
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string component;
        string ans;

        for (char c : path) {

            if (c == '/') {

                if (component == "..") {
                    if (!st.empty()) {
                        st.pop();
                    }
                }
                else if (component != "" && component != ".") {
                    st.push(component);
                }

                component = "";
            }
            else {
                component += c;
            }
        }

        if (component == "..") {
            if (!st.empty()) {
                st.pop();
            }
        }
        else if (component != "" && component != ".") {
            st.push(component);
        }

        while (!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }

        return ans.empty() ? "/" : ans;
    }
};