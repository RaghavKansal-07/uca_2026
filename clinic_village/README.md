# Clinic and Village

## Problem

Given n villages and k clinics, distribute the clinics among the villages such that every village has at least one clinic and the maximum number of patients served by any single clinic is minimized.

## Approach

The problem is solved using binary search on the answer.

For a given maximum allowed patient load, we calculate how many clinics each village requires:

clinics required = ceil(population / maximum load)

We calculate this for every village and add the required clinics.

- If the total number of required clinics is less than or equal to k, the maximum load is feasible.
- If the total number of required clinics is greater than k, the maximum load is not feasible.

Binary search is performed between 0 and the maximum village population until the required precision is achieved.

## Algorithm

1. Find the maximum population among all villages.
2. Set the binary search range from 0 to the maximum population.
3. Calculate the middle value as the candidate maximum load.
4. Calculate the number of clinics required for this candidate load.
5. If the required clinics are at most k, search for a smaller load.
6. Otherwise, search for a larger load.
7. Repeat the process for sufficient precision.
8. Return the minimum feasible maximum load.

## Time Complexity

For a fixed precision, the binary search performs a constant number of iterations.

Time complexity: O(n)

## Space Complexity

O(1), excluding the input array.

## Example

Input:

n = 3

population = [200, 20, 50]

k = 5

Optimal clinic allocation:

[3, 1, 1]

Loads:

200 / 3 = 66.67

20 / 1 = 20

50 / 1 = 50

Therefore, the minimum possible maximum load is:

66.67
