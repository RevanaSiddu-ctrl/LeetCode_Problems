/*
-------------------------------------------------------
Problem: 525. Contiguous Array
Difficulty: Medium
Topic: Arrays, HashMap, Prefix Sum

Pattern:
- Prefix Sum + HashMap

Approach:
1. Convert every 0 to -1 and every 1 to +1.
2. Maintain a running prefix sum while traversing the array.
3. If the same prefix sum appears again, the elements between the
   two indices have a sum of 0, meaning they contain an equal
   number of 0s and 1s.
4. Store only the first occurrence of each prefix sum to maximize
   the length of the valid subarray.

Concepts Learned:
- Converting a problem into a Prefix Sum problem
- Using Prefix Sum to detect zero-sum subarrays
- HashMap stores Prefix Sum -> First Index
- First occurrence gives the longest possible subarray
- Difference between counting subarrays (frequency) and finding
  the longest subarray (first occurrence)

Time Complexity: O(n)
Space Complexity: O(n)
-------------------------------------------------------
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;

        int sum = 0;
        int maxLen = 0;
        mp[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                sum--;
            else
                sum++;
            if (mp.find(sum) != mp.end()) {
                maxLen = max(maxLen, i - mp[sum]);
            } else {
                mp[sum] = i;
            }
        }
        return maxLen;
    }
};