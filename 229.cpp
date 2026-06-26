/*
    Problem: 229. Majority Element II
    Link: https://leetcode.com/problems/majority-element-ii/

    Approach:
    - Use an unordered_map to store the frequency of each element.
    - Use a set to avoid adding duplicate majority elements.

    Time Complexity: O(N log N)
    Space Complexity: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp;
        set<int> st;

        for (int x : nums) {
            mp[x]++;

            if (mp[x] > n / 3) {
                st.insert(x);
            }
        }

        return vector<int>(st.begin(), st.end());
    }
};