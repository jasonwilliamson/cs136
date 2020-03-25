/*
 *    Sort.h
 * This module provides some functions for sorting arrays
 */

// sort_str(char *a[], int len) sorts the array a
//   requires: len >= 0; a is an array of length >= len
//   effects: a is sorted in lexicographic order
//   time: O(m*n*log n), where n is len and
//         m is  the longest string in a
//   (note that this assumes the strings have a constant maximum length)
void sort_str(char *a[], int len);

// sort_int(int a[], int len) sorts the array a
// requires: len >= 0; a is an array of length >= len
// effects: a is sorted in ascending order
// time: O(n log n) where n is len
void sort_int(int a[], int len);

// sort_char(int a[], int len) sorts the array a
// requires: len >= 0; a is an array of length >= len
// effects: a is sorted in ascending ASCII order
// time: O(n log n) where n is len
void sort_char(char a[], int len);
