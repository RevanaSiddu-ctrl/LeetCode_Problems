/*
-------------------------------------------------------
Problem: 560. Subarray Sum Equals K
Difficulty: Medium
Topic: Arrays, HashMap, Prefix Sum

Pattern:
- Prefix Sum + HashMap

Approach:
1. Maintain a running prefix sum while traversing the array.
2. For each prefix sum, check whether (currentPrefixSum - k)
   has appeared before.
3. If found, add its frequency to the answer since each occurrence
   represents a valid subarray.
4. Store the current prefix sum in the hash map for future lookups.

Concepts Learned:
- Prefix Sum technique
- HashMap for storing prefix sum frequencies
- Difference between storing prefix sums and searching for (sum - k)
- Counting multiple subarrays using prefix sum frequency
- Importance of initializing mp[0] = 1

Time Complexity: O(n)
Space Complexity: O(n)
-------------------------------------------------------
*/
class Solution {
    public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt=0;
        int sum =0;
        unordered_map<int, int> mp;
        mp[0]=1;
        int leftout;
        for(int x : nums){
            sum+=x;
            leftout = sum - k;
            if(mp.find(leftout)!=mp.end()){
                cnt+=mp[leftout];
            }
            mp[sum]++;
        }
        return cnt;
    }
};