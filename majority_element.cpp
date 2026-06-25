/*
Problem: 169. Majority Element
Link: https://leetcode.com/problems/majority-element/

Approach: Hashing using unordered_map

Algorithm:
1. Create a hash map to store the frequency of each element.
2. Traverse the array and increment the frequency.
3. If the frequency of an element becomes greater than n/2,
   return that element.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        int n = nums.size();

        for (int x : nums) {
            freq[x]++;

            if (freq[x] > n / 2) {
                return x;
            }
        }

        // According to the problem constraints,
        // this line will never be executed.
        return -1;
    }
};