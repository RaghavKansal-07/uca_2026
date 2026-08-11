# Matrix Zeroes

## Problem

Given an m x n integer matrix, if an element is 0, set its entire row and column to 0.

The operation must be performed in-place.

## Approach

The solution uses the first row and first column of the matrix as markers to achieve constant extra space.

First, we check whether the first row or first column originally contains a zero. These cases are stored separately using two variables.

Then, while traversing the remaining matrix, whenever a zero is found at position (i, j), the first element of its row and column is set to zero:

matrix[i][0] = 0
matrix[0][j] = 0

These markers are then used to determine which cells should become zero.

Finally, the first row and first column are zeroed if they originally contained a zero.

## Algorithm

1. Check whether the first row contains a zero.
2. Check whether the first column contains a zero.
3. Use the first row and first column as markers for the remaining rows and columns.
4. Traverse the matrix and mark the corresponding row and column whenever a zero is found.
5. Use the markers to set the required cells to zero.
6. Zero the first row if required.
7. Zero the first column if required.

## Example

Input:

1 1 1
1 0 1
1 1 1

Output:

1 0 1
0 0 0
1 0 1

## Complexity

Time Complexity: O(m × n)

Space Complexity: O(1)

The matrix is modified in-place and no additional row or column arrays are used.
