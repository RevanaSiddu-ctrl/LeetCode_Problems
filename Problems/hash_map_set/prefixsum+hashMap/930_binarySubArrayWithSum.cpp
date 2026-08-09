/*
-------------------------------------------------------
Problem: 930. Binary Subarrays With Sum
Difficulty: Medium
Topic: Arrays, HashMap, Prefix Sum

Pattern:
- Prefix Sum + HashMap

Approach:
1. Maintain a running prefix sum while traversing the array.
2. For each current prefix sum, calculate:
   diff = sum - goal
3. If diff has appeared before, every occurrence represents a
   subarray whose sum is equal to goal.
4. Add the frequency of diff to the answer.
5. Store the current prefix sum with its frequency for future
   lookups.
6. Initialize mp[0] = 1 to handle subarrays starting from index 0.

Concepts Learned:
- Prefix Sum technique
- HashMap: Prefix Sum -> Frequency
- Current sum - goal gives the previous prefix sum we need
- Counting multiple valid subarrays using frequency
- Difference between searching (sum - goal) and storing current sum

Time Complexity: O(n)
Space Complexity: O(n)
-------------------------------------------------------
*/

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int , int> mp;
        int cnt = 0;
        int sum = 0;
        int diff;
        mp[0]=1;
        for(int x : nums){
            sum+=x;
            diff = sum-goal;
                cnt+=mp[diff];
                mp[sum]++;
        }
        return cnt;
    }
};