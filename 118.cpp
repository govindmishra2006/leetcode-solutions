/*
    Problem: Pascal Triangle I (Find the element at row r and column c)

    Brute Force:
    - Use the recursive relation:
      C(r, c) = C(r-1, c-1) + C(r-1, c)

    Time Complexity: O(2^r)
    Space Complexity: O(r)

    Optimal:
    - The element at (r, c) is:
      C(r-1, c-1)
    - Compute nCr iteratively.

    Time Complexity: O(min(c-1, r-c))
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // ---------------- Brute Force (Recursion) ----------------
    int pascalTriangleBrute(int r, int c) {
        if (c == 1 || c == r) {
            return 1;
        }

        return pascalTriangleBrute(r - 1, c - 1) +
               pascalTriangleBrute(r - 1, c);
    }

    // ---------------- Optimal (nCr) ----------------
    int pascalTriangleOptimal(int r, int c) {
        int n = r - 1;
        int k = c - 1;

        // Use the smaller value of k
        if (k > n - k) {
            k = n - k;
        }

        long long ans = 1;

        for (int i = 1; i <= k; i++) {
            ans = ans * (n - i + 1);
            ans = ans / i;
        }

        return (int)ans;
    }
};