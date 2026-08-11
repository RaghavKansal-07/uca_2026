# Base64 Encoding

## Problem

The program accepts an ASCII string and returns its Base64 encoded equivalent without using any built-in Base64 encoding library.

## Approach

Base64 encoding converts every 3 bytes of input into 4 groups of 6 bits.

Each 6-bit value is used as an index in the Base64 character table:

ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/

The program processes the input in groups of three bytes.

For every group, the bytes are combined and divided into four 6-bit values using bit shifting and bitwise AND operations.

These values are then mapped to characters using the Base64 lookup table.

## Padding

If the input length is not a multiple of 3, padding is added.

- 3 bytes → no padding
- 2 bytes → one `=`
- 1 byte → two `=`

## Algorithm

1. Read the ASCII input string.
2. Process the input three bytes at a time.
3. Extract four 6-bit values using bitwise operations.
4. Map each value to the Base64 character table.
5. Add `=` padding when required.
6. Return the Base64 encoded string.

## Example

Input:

Man

Output:

TWFu

Input:

Ma

Output:

TWE=

Input:

A

Output:

QQ==

## Complexity

Time Complexity: O(n)

Space Complexity: O(n)

where n is the length of the input string.
