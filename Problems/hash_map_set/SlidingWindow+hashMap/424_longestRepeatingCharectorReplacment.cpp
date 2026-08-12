/*
-------------------------------------------------------
Problem: 424. Longest Repeating Character Replacement
Difficulty: Medium
Topic: Strings, HashMap, Sliding Window

Pattern:
- Variable-Size Sliding Window + Frequency Map

Approach:
1. Maintain a sliding window using two pointers i and j.
2. Store the frequency of each character inside the current window.
3. Track max_freq, the highest frequency of any character in
   the current window.
4. The number of characters that need to be replaced is:
      window length - max_freq
5. If the number of replacements needed is greater than k,
   shrink the window from the left.
6. Once the window becomes valid, update max_len.
7. max_freq does not need to decrease when shrinking because
   keeping the maximum seen frequency still gives the correct
   maximum window length.

Concepts Learned:
- Variable-size sliding window
- Frequency map
- Tracking the most frequent character
- Window validity using:
  (window length - max_freq) <= k
- Shrinking the window when more than k replacements are needed

Time Complexity: O(n)
Space Complexity: O(1)  // At most 26 characters
-------------------------------------------------------
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int max_len=0, max_freq;
        int j=0;
        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
            max_freq= max(max_freq, mp[s[i]]);
            while((i-j+1)-max_freq>k){
                mp[s[j]]--;
                j++;
            }
            max_len = max(max_len, i-j+1);
        }
        return max_len;
    }
};