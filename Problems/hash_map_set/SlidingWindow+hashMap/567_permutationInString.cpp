/*
-------------------------------------------------------
Problem: 567. Permutation in String
Difficulty: Medium
Topic: Strings, HashMap, Sliding Window

Pattern:
- Fixed-Size Sliding Window + Frequency Map

Approach:
1. Count the frequency of each character in s1.
2. Maintain a sliding window in s2 with size equal to s1.size().
3. Use req to track the total number of required characters
   that are still unmatched.
4. When adding a character from the right:
   - If it is still required, decrease req.
   - Decrease its frequency in the map.
5. When the window becomes larger than s1.size(), remove the
   leftmost character and restore its frequency.
6. If removing a character creates a new requirement, increase req.
7. If req becomes 0 after maintaining the fixed window size,
   the current window is a permutation of s1.

Concepts Learned:
- Fixed-size sliding window
- Character frequency counting
- Tracking required characters with req
- Negative frequency values represent extra characters
- Shrinking the window from the left

Time Complexity: O(n)
Space Complexity: O(1)  // At most 26 characters
-------------------------------------------------------
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())
            return false;
        unordered_map<char , int> mp;
        int req = s1.size();
        int i = 0;
        for(char c : s1){
            mp[c]++;
        }
        for(int j =0; j<s2.size(); j++){
            if(mp[s2[j]]>0){
                req--;
            }
            mp[s2[j]]--;
            if(j-i+1>s1.size()){
                if(mp[s2[i]]>=0){
                    req++;
                }
                mp[s2[i]]++;
                i++;
            }
            if(req==0) return true;
        }
        return false;
    }
};