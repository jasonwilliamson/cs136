// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 07, Problem 5
// File: trinary.h
// ====================================================
//

// A module that provides the function trinary_search, this function
// does not return a value but prints out information about the steps performed
// at runtime.

#include <stdio.h>


// trinary_search(*a,n,v) consumes *a a pointer to a sorted array of integers,
// n an int that represents the length of array a, and v, an int to be searched for
// within array a. trinary_search divides the array into three smaller search regions
// (having lengths as equal as possible) at each iteration.
// requires:*a must not be null.
//          *a must be a pointer to a sorted array.
// time: O(log n)
void trinary_search(int *a, int n, int v);
