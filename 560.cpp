/*
    Problem: 560. Subarray Sum Equals K
    Link: https://leetcode.com/problems/subarray-sum-equals-k/

    Approach:
    - Use a prefix sum and a hash map to store the frequency
      of each prefix sum encountered.
    - If the current prefix sum is 'sum', then any previous
      prefix sum equal to (sum - k) forms a subarray with sum k.

    Time Complexity: O(N)
    Space Complexity: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int prefixSum = 0;
        int count = 0;

        for (int num : nums) {
            prefixSum += num;

            if (mp.find(prefixSum - k) != mp.end()) {
                count += mp[prefixSum - k];
            }

            mp[prefixSum]++;
        }

        return count;
    }
};