# Running Median in Data Stream

## Problem

Given a stream of integers, support two operations:

- insert(int num): Insert a number into the data structure.
- getMedian(): Return the median of all numbers received so far.

## Approach

The solution uses two heaps.

A max heap stores the smaller half of the numbers, while a min heap stores the larger half.

The max heap is allowed to contain at most one more element than the min heap.

When a new number is inserted, it is placed into the appropriate heap. The heaps are then rebalanced if their sizes differ by more than one.

## Finding the Median

If the max heap has one extra element, its root is the median.

If both heaps have the same size, the median is the average of the roots of the two heaps.

## Data Structures

Max Heap:
Stores the smaller half of the numbers.

Min Heap:
Stores the larger half of the numbers.

## Complexity

Insert: O(log n)

Get Median: O(1)

Space: O(n)

## Example

Input stream:

10, 5, 2, 8, 15

Running medians:

10.00
7.50
5.00
6.50
8.00
