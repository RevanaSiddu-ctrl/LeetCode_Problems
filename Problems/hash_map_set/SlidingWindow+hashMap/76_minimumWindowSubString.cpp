/*
-------------------------------------------------------
Problem: 76. Minimum Window Substring
Difficulty: Hard
Topic: Strings, HashMap, Sliding Window

Pattern:
- Variable-Size Sliding Window + Frequency Map

Approach:
1. Count the frequency of every character required from t.
2. Use two pointers to maintain a sliding window in s.
3. Expand the window using the right pointer.
4. If a required character is added, decrease req.
5. When req becomes 0, the current window contains all
   characters required by t.
6. Shrink the window from the left while it remains valid.
7. Whenever a valid window is found, update min_len and start
   if it is smaller than the previous minimum.
8. After processing the string, return the substring starting
   at start with length min_len.

Concepts Learned:
- Variable-size sliding window
- Frequency map for required characters
- req tracks the total number of required characters remaining
- Positive frequency → character is still needed
- Zero frequency → exactly satisfied
- Negative frequency → extra character in the window
- Shrink while the window remains valid to find the minimum

Time Complexity: O(n)
Space Complexity: O(1)  // At most 128/256 characters
-------------------------------------------------------
*/
class Solution {
    public:
        string minWindow(string s, string t) {
            if(s.size()<t.size()) return "";
            int min_len = INT_MAX;
            string ans;
            int start =0;
            unordered_map<char, int> mp;
            for(char x : t){
                mp[x]++;
            }
            int req = t.size();
            int j=0;
            for(int i =0; i<s.size(); i++){
                if(mp[s[i]]>0){
                    req--;
                }
                mp[s[i]]--;
                while(req==0){
                    if(i-j+1<min_len){
                        min_len = i-j+1;
                        start = j;
                    }
                    if(mp[s[j]]>=0){
                        req++;
                    }
                    mp[s[j]]++;
                    j++;
                }
            }
            if(min_len==INT_MAX){
                return "";
            }
            return s.substr(start, min_len);
        }
    };