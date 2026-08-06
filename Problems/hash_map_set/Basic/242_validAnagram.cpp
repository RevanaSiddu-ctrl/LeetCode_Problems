/*
-------------------------------------------------------
Problem: 242. Valid Anagram
Difficulty: Easy
Topic: Strings, HashMap

Pattern:
- Character Frequency Counting

Approach:
1. If both strings have different lengths,
   return false.
2. Count the frequency of each character in the first string.
3. Decrease the frequency while traversing the second string.
4. If any character count becomes negative,
   return false.
5. If all counts are balanced, return true.

Concepts Learned:
- Character frequency counting
- Using unordered_map for counting occurrences
- Increment and decrement frequency technique
- Comparing two datasets using a frequency map

Time Complexity: O(n)
Space Complexity: O(n)
-------------------------------------------------------
*/  
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;

        for(char x : s){
            mp1[x]++;
        }
        for(char x : t){
            mp2[x]++;
        }

        if(mp1==mp2){
            return true;
        }
        
        return false;
    }
};