# Heap Sort

## Problem

Implement Heap Sort by first converting the input array into a valid max heap and then repeatedly removing the maximum element to produce a sorted array.

The algorithm is also tested on random, ascending, and descending input arrays.

## Approach

The input array is converted into a max heap using the heapify procedure.

Starting from the last non-leaf node, heapify is applied down to the root.

After constructing the max heap, the maximum element is present at index 0. It is swapped with the last element of the unsorted portion of the array. The heap size is then reduced and heapify is applied again.

This process is repeated until the complete array is sorted in ascending order.

## Heapify

For an element at index i:

- Left child = 2i + 1
- Right child = 2i + 2

The largest among the current element and its children is moved to the root of the current subtree.

## Validation

The program verifies that the resulting array is sorted in ascending order after every test.

The following input cases are tested:

1. Randomly ordered array
2. Array already sorted in ascending order
3. Array already sorted in descending order

## Runtime Analysis

The execution time is measured using the C clock() function.

The program tests different input sizes:

1000, 2000, 5000, 10000, 20000, 50000, 100000

Each test is repeated multiple times and the average runtime is reported.

## Complexity

Time Complexity:

Best Case: O(n log n)

Average Case: O(n log n)

Worst Case: O(n log n)

Space Complexity:

O(1) auxiliary space because Heap Sort is performed in-place.

## Result

The runtime results are plotted in a graph comparing random, ascending, and descending input arrays.
