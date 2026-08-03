/*
Problem:Group Anagrams
Difficulty:Medium
Topic:HashMap, Strings

Pattern: Hash map, sorting

Approach:
- If same string then same chrar frequency, so sort and as per the sorted string store them in hasp map;
- Have a vector of vetor of string to store the result and return it.

Concepts Learned: String sorting, hash map, vector of vector of string

Time Complexity: O(n * m * log(m))
Space Complexity: O(n * m)
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> result;
        for(string s : strs){
            string key = s;
            sort(key.begin(),key.end());
            mp[key].push_back(s);
        }
        for(auto it : mp){
            result.push_back(it.second);
        }
        return result;
    }
};