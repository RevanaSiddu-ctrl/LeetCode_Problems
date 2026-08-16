/*
-------------------------------------------------------
Problem: 219. Contains Duplicate II
Difficulty: Easy
Topic: Arrays, HashMap, Sliding Window

Pattern:
- HashMap to store the most recent index of each number

Approach:
1. Create an unordered_map to store:
   - Key   → Number
   - Value → Most recent index of that number
2. Traverse the array from left to right.
3. For each number, check whether it already exists in the map.
4. If it exists, calculate the distance between:
   - Current index
   - Previous index of the same number
5. If the distance is <= k, return true.
6. Otherwise, update the number's index with the current index.
7. If no valid duplicate is found after traversing the array,
   return false.

Concepts Learned:
- Using unordered_map for fast lookup
- Storing the index of an element as the map value
- Finding duplicates efficiently
- Checking distance between duplicate indices
- Updating the most recent index of each element

Time Complexity: O(n)
Space Complexity: O(n)

Why store the latest index?
- We only need the closest previous occurrence.
- If the latest occurrence is more than k positions away,
  any older occurrence will be even farther away.
-------------------------------------------------------
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i =0; i<nums.size(); i++){
            if(mp.find(nums[i])!=mp.end() && abs(mp[nums[i]]-i)<=k){
                return true;
            }
            mp[nums[i]] = i;
        }
        return false;
    }
};