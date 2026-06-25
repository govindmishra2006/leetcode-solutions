/*
Problem: Sort an array of 0s, 1s and 2s
Approach: Counting Method

Algorithm:
1. Count the number of 0s, 1s, and 2s.
2. Overwrite the array with the counted numbers.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;

        for (int num : nums) {
            if (num == 0)
                cnt0++;
            else if (num == 1)
                cnt1++;
            else
                cnt2++;
        }

        int i = 0;

        while (cnt0--) nums[i++] = 0;
        while (cnt1--) nums[i++] = 1;
        while (cnt2--) nums[i++] = 2;
    }
};