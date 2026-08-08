/*
-------------------------------------------------------
Problem: 523. Continuous Subarray Sum
Difficulty: Medium
Topic: Arrays, HashMap, Prefix Sum

Pattern:
- Prefix Sum + Modulo + HashMap

Approach:
1. Maintain a running prefix sum while traversing the array.
2. Calculate the remainder of the prefix sum when divided by k.
3. If the same remainder appeared before, the sum of the elements
   between the two indices is divisible by k.
4. Check that the subarray contains at least two elements.
5. Store only the first index at which each remainder appears.
6. Do not overwrite an existing remainder index because the earliest
   occurrence gives the longest possible subarray.

Concepts Learned:
- Prefix Sum with modulo
- HashMap: Remainder -> First Index
- Equal remainders indicate a subarray whose sum is divisible by k
- Keeping the first occurrence to maximize subarray length
- Using mp[0] = -1 to handle subarrays starting from index 0

Time Complexity: O(n)
Space Complexity: O(n)
-------------------------------------------------------
*/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum = 0;
        mp[0]  = -1;
        int rem;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            rem = sum%k;
            if(mp.find(rem)!=mp.end()){
                if(i-mp[rem]>1){
                    return true;
                }
            }
            if(mp.find(rem)==mp.end()){
                mp[rem]=i;
            }
        }
        return false;
    }
};