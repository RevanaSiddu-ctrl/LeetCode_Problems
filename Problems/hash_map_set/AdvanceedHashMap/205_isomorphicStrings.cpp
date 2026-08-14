/*
-------------------------------------------------------
Problem: 205. Isomorphic Strings
Difficulty: Easy
Topic: Strings, HashMap

Pattern:
- Two-Way HashMap Mapping

Approach:
1. Check whether both strings have the same length.
2. Maintain two HashMaps:
   - mp1: maps characters from s -> t
   - mp2: maps characters from t -> s
3. For each pair of characters:
   - If s[i] was already mapped, verify that it maps to t[i].
   - If t[i] was already mapped, verify that it maps to s[i].
4. If either mapping conflicts, return false.
5. Otherwise, store both mappings.
6. If all characters satisfy the one-to-one mapping, return true.

Why Two Maps?
- One map ensures each character in s always maps to the same
  character in t.
- The second map ensures two different characters in s cannot
  map to the same character in t.

Concepts Learned:
- Character-to-character HashMap mapping
- Bidirectional / one-to-one mapping
- Checking an existing mapping before updating it
- Detecting conflicting mappings

Time Complexity: O(n)
Space Complexity: O(1)  // At most 256 possible characters
-------------------------------------------------------
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;
        if(s.size()!=t.size()) return false;
        for(int i=0; i<s.size(); i++){
            if(mp1.find(s[i])!=mp1.end()&&mp1[s[i]]!=t[i]){
                return false;
            }
            if(mp2.find(t[i])!=mp2.end()&&mp2[t[i]]!=s[i]){
                return false;
            }
            mp1[s[i]]=t[i];
            mp2[t[i]]=s[i];
        }
        return true;
    }
};