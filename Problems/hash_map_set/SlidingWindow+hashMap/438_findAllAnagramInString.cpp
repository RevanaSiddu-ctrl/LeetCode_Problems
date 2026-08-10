/*
-------------------------------------------------------
Problem: 438. Find All Anagrams in a String
Difficulty: Medium
Topic: Strings, HashMap, Sliding Window

Pattern:
- Fixed-Size Sliding Window + Frequency Map

Approach:
1. Count the frequency of each character in p.
2. Maintain a sliding window in s with size equal to p.size().
3. Use req to track the total number of required characters
   that are still unmatched.
4. When adding a character from the right:
   - If it is still required, decrease req.
   - Decrease its frequency in the map.
5. If the window becomes larger than p.size(), remove the
   leftmost character and restore its frequency.
6. If removing a character creates a new requirement, increase req.
7. When req becomes 0, the current window is an anagram of p.
8. Store the starting index of the valid window in the answer.

Concepts Learned:
- Fixed-size sliding window
- Character frequency counting
- Tracking required characters using req
- Handling extra characters using negative frequencies
- Shrinking the window from the left
- Finding all valid windows instead of returning after the first match

Time Complexity: O(n)
Space Complexity: O(1)  // At most 26 characters
-------------------------------------------------------
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<char, int> mp;
        int i=0;
        int req = p.size();
        for(char c: p){
            mp[c]++;
        }
        for(int j = 0; j<s.size(); j++){
            if(mp[s[j]]>0){
                req--;
            }
            mp[s[j]]--;
            if(j-i+1>p.size()){
                if(mp[s[i]]>=0){
                    req++;
                }
                mp[s[i]]++;
                i++;
            }
            if(req==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};