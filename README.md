# Dictionary Merge Project

## Description

This project is a continuation of Project 1. In this project, we implement two algorithms to merge two dictionaries:

### Algorithm 1
This algorithm takes one dictionary and inserts the elements of the other dictionary one by one using the `InsertElement` function (assumed to be available from Project 1).

### Algorithm 2
This algorithm obtains the `StartingIndex` for both dictionaries and creates a third array with a size equal to the total size of both dictionaries to be merged. It then compares the dictionary values at the `StartingIndex` for both arrays and inserts the elements into the third array in a sorted manner until all elements from both arrays are transferred.

After implementing the algorithms, we provide a complexity analysis for both algorithms to determine the most efficient one in terms of time and space usage.

## Usage

1. Ensure you have the `InsertElement` function available (from Project 1).
2. Implement or call the algorithms as needed for your specific use case.

## Complexity Analysis

### Algorithm 1
- Time Complexity: O(N), where N is the size of the second dictionary.
- Space Complexity: O(1) since it doesn't require additional memory.

### Algorithm 2
- Time Complexity: O(N + M), where N is the size of the first dictionary, and M is the size of the second dictionary.
- Space Complexity: O(N + M) due to the creation of a third array.

