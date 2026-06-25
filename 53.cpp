/*
Problem: 53. Maximum Subarray
Link: https://leetcode.com/problems/maximum-subarray/

Approach: Kadane's Algorithm

Algorithm:
1. Maintain a running sum of the current subarray.
2. Update the maximum subarray sum encountered so far.
3. If the running sum becomes negative, reset it to 0.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxSum = INT_MIN;

        for (int x : nums) {
            sum += x;
            maxSum = max(maxSum, sum);

            if (sum < 0) {
                sum = 0;
            }
        }

        return maxSum;
    }
};