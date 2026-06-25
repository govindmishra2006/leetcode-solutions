/*
Problem: 128. Longest Consecutive Sequence
Link: https://leetcode.com/problems/longest-consecutive-sequence/

Approach: Hashing using unordered_set

Intuition:
For every number, we only start counting a sequence if it is the
beginning of a sequence, i.e., if (num - 1) does not exist.

Example:
nums = [100, 4, 200, 1, 3, 2]

Set = {100, 4, 200, 1, 3, 2}

1 is the start of a sequence because 0 is not present.
Sequence:
1 -> 2 -> 3 -> 4

Length = 4.

This avoids repeatedly traversing the same sequence and gives
an O(n) solution.

Time Complexity: O(n) average
Space Complexity: O(n)
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int longest = 0;

        for (int num : st) {
            // Check if num is the start of a sequence
            if (st.find(num - 1) == st.end()) {
                int currentNum = num;
                int currentLength = 1;

                while (st.find(currentNum + 1) != st.end()) {
                    currentNum++;
                    currentLength++;
                }

                longest = max(longest, currentLength);
            }
        }

        return longest;
    }
};