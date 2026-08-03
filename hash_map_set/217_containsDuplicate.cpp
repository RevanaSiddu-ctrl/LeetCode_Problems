/*
-------------------------------------------------------
Problem: 217. Contains Duplicate
Difficulty: Easy
Topic: Arrays, HashSet

Pattern:
- HashSet

Approach:
1. Traverse the array.
2. Store every element in a hash set.
3. If an element is already present,
   return true.
4. Otherwise insert it.
5. If traversal completes, return false.

Concepts Learned:
- Fast existence checking
- unordered_set operations
- Difference between HashSet and HashMap
- Average O(1) insertion and lookup

Time Complexity: O(n)
Space Complexity: O(n)
-------------------------------------------------------
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for(int x: nums){
            if(set.find(x)!=set.end()){
                return true;
            }
            set.insert(x);
        }
        return false;
    }