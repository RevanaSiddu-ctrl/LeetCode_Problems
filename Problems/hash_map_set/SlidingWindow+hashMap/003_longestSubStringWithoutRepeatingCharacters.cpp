/*
-------------------------------------------------------
Problem: 3. Longest Substring Without Repeating Characters
Difficulty: Medium
Topic: Strings, HashMap, Sliding Window

Pattern:
- Variable-Size Sliding Window + Frequency Map

Approach:
1. Maintain a sliding window using two pointers i and j.
2. Add each character from the right side to the frequency map.
3. If the current character appears more than once, move the
   left pointer forward until the duplicate is removed.
4. Update the maximum window length after the window becomes valid.
5. The current window always contains unique characters.

Concepts Learned:
- Variable-size sliding window
- Frequency map for detecting duplicates
- Shrinking the window only when it becomes invalid
- Maintaining a valid window before calculating its length

Time Complexity: O(n)
Space Complexity: O(1)  // At most 128/256 characters
-------------------------------------------------------
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int j = 0;
        int cnt = 0;
        for(int i = 0 ;i<s.size(); i++){
            mp[s[i]]++;
                while(mp[s[i]]>1){
                    mp[s[j]]--;
                    j++;
                }
            cnt = max(cnt, i-j+1);
        }
        return cnt;
    }
};