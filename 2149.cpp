/*
Problem: 2149. Rearrange Array Elements by Sign
Link: https://leetcode.com/problems/rearrange-array-elements-by-sign/

Approach:
- Traverse the answer array index by index.
- For every even index, find the next positive element.
- For every odd index, find the next negative element.
- Maintain two pointers:
    i -> last positive element used.
    j -> last negative element used.

Time Complexity: O(n^2)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int i = -1; // last positive index used
        int j = -1; // last negative index used

        for (int k = 0; k < n; k++) {
            if (k % 2 == 0) {
                for (int l = i + 1; l < n; l++) {
                    if (nums[l] > 0) {
                        ans[k] = nums[l];
                        i = l;
                        break;
                    }
                }
            }
            else {
                for (int l = j + 1; l < n; l++) {
                    if (nums[l] < 0) {
                        ans[k] = nums[l];
                        j = l;
                        break;
                    }
                }
            }
        }

        return ans;
    }
};