"""
Problem: 48. Rotate Image
Link: https://leetcode.com/problems/rotate-image/

Intuition:
A 90-degree clockwise rotation can be achieved in two steps:

1. Transpose the matrix:
   Convert rows into columns by swapping
   matrix[i][j] with matrix[j][i].

2. Reverse every row:
   After transposing, reversing each row
   gives the desired 90-degree clockwise rotation.

Example:

1 2 3        1 4 7        7 4 1
4 5 6   ->   2 5 8   ->   8 5 2
7 8 9        3 6 9        9 6 3

Approach:
1. Traverse only the upper triangle of the matrix
   and transpose it in-place.
2. Reverse each row.

Time Complexity: O(n²)
Space Complexity: O(1)
"""

class Solution(object):
    def rotate(self, matrix):
        n = len(matrix)

        # Step 1: Transpose the matrix
        for i in range(n):
            for j in range(i + 1, n):
                matrix[i][j], matrix[j][i] = (
                    matrix[j][i],
                    matrix[i][j]
                )

        # Step 2: Reverse each row
        for row in matrix:
            row.reverse()