/*
-------------------------------------------------------
Problem: 1. Two Sum
Difficulty: Easy
Topic: Arrays, HashMap

Pattern:
- HashMap (Value → Index)

Approach:
1. Traverse the array once.
2. Compute the complement (target - current element).
3. If the complement already exists in the hash map,
   return both indices.
4. Otherwise, store the current element and its index.

Concepts Learned:
- HashMap lookup before insertion
- Complement technique
- Trade-off between time and space
- Average O(1) lookup using unordered_map

Time Complexity: O(n)
Space Complexity: O(n)
-------------------------------------------------------
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            int x = target-nums[i];
            if(mp.find(x)==mp.end()){
                mp[nums[i]]=i;
            }else{
                return {i, mp[x]};
            }
        }
        return {};
    }
};
