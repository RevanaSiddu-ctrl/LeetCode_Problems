/*
-------------------------------------------------------
Problem: 347. Top K Frequent Elements
Difficulty: Medium
Topic: HashMap, Sorting

Pattern:
- Frequency Counting
- HashMap + Sorting

Approach:
1. Count the frequency of each element using a hash map.
2. Store each {frequency, element} pair in a vector.
3. Sort the vector in descending order of frequency.
4. Extract the first k elements from the sorted vector.

Concepts Learned:
- Frequency counting using unordered_map
- Storing data as pair<frequency, element>
- Sorting a vector of pairs
- Difference between frequency threshold and top-k elements

Time Complexity: O(n log n)
Space Complexity: O(n)
-------------------------------------------------------
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> mp;
        vector<pair<int, int>> temp;
        for(int x : nums){
            mp[x]++;
        }
        for(auto it: mp){
            temp.push_back({it.second, it.first});
        }
        sort(temp.rbegin(), temp.rend());
        for(int i = 0; i<k;i++){
            res.push_back(temp[i].second);
        }
        return res;
        
    }
};