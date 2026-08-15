/*
-------------------------------------------------------
Problem: 290. Word Pattern
Difficulty: Easy
Topic: Strings, HashMap

Pattern:
- Two-Way HashMap Mapping

Approach:
1. Split the string s into individual words.
2. Check whether the number of words matches the length of pattern.
3. Maintain two HashMaps:
   - mp1: maps pattern character -> word
   - mp2: maps word -> pattern character
4. For each character and corresponding word:
   - If the character already has a mapping, verify that it maps
     to the same word.
   - If the word already has a mapping, verify that it maps
     to the same character.
5. If either mapping conflicts, return false.
6. Otherwise, store both mappings.
7. If all mappings remain consistent, return true.

Why Two Maps?
- mp1 ensures one pattern character always maps to the same word.
- mp2 ensures two different pattern characters cannot map to
  the same word.

Concepts Learned:
- HashMap with different key/value types
- Bidirectional one-to-one mapping
- Splitting a string into words
- Detecting conflicting mappings

Time Complexity: O(n)
Space Complexity: O(n)
-------------------------------------------------------
*/
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;

        vector<string> words;
        string word;

        stringstream ss(s);

        while (ss >> word) {
            words.push_back(word);
        }

        if (pattern.size() != words.size())
            return false;

        for (int i = 0; i < pattern.size(); i++) {

            if (mp1.find(pattern[i]) != mp1.end() &&
                mp1[pattern[i]] != words[i]) {
                return false;
            }

            if (mp2.find(words[i]) != mp2.end() &&
                mp2[words[i]] != pattern[i]) {
                return false;
            }

            mp1[pattern[i]] = words[i];
            mp2[words[i]] = pattern[i];
        }

        return true;
    }
};