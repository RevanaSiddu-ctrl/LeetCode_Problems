/*
-------------------------------------------------------
Problem: 974. Subarray Sums Divisible by K
Difficulty: Medium
Topic: Arrays, HashMap, Prefix Sum

Pattern:
- Prefix Sum + Modulo + HashMap

Approach:
1. Maintain a running prefix sum while traversing the array.
2. Calculate the normalized remainder of the prefix sum modulo k.
3. If the same remainder has appeared before, the subarray between
   the two prefix sums has a sum divisible by k.
4. Add the frequency of the remainder to the answer because every
   previous occurrence forms a valid subarray.
5. Increment the frequency of the current remainder.

Concepts Learned:
- Prefix Sum with modulo
- HashMap: Remainder -> Frequency
- Equal remainders indicate a subarray whose sum is divisible by k
- Counting multiple valid subarrays using remainder frequency
- Handling negative remainders in C++ using:
  ((sum % k) + k) % k
- Difference between storing frequency and first index

Time Complexity: O(n)
Space Complexity: O(k)
-------------------------------------------------------
*/


class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int , int> mp;
        int sum = 0;
        int rem;
        int cnt = 0;
        mp[0]=1;
        for(int x : nums){
            sum+=x;
            rem = ((sum % k) + k) % k;
            
            if(mp.find(rem)!=mp.end()){
                cnt+=mp[rem];
                mp[rem]++;
            }else{
                mp[rem]=1;
            }
        }
        return cnt;
    }
};