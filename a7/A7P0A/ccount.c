// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 07, Problem 0B
// File: ccount.c
// ====================================================

// A module that provides the function
// int ccount(char *strings[], int num, char c) which takes
// an array of strings, its length num and a character c, and returns
// the number of strings in the array that contain c

#include "ccount.h"
#include "sort.h"
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


// ccount_char(*a,c) consumes an array of char, and a char, c. Returning
// the number of times c is present in array a.
// requires: char *a be null terminated
static int count_char( char *a, char c){
    int count = 0;
    while (*a) {
        if (c == *a){
            ++count;
        }
        ++a;
    }
    return count;
}


// ccount(strings,num,c) consumes an array of strings, its length, num, and
// a character c, and returns the number of strings in the array that contain c
// time: O(n) where n is num
int ccount(char *strings[], int num, char c) {
    int count = 0;
    for (int i = 0; i < num; ++i) {
        count += count_char(strings[i], c);
    }
    return count;
}