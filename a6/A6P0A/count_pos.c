// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 06, Problem 0a
// File: count_pos.c
// ====================================================
//

#include "count_pos.h"
#include <assert.h>
#include <stdlib.h>

// count_pos(a, len) determines the number of positive integers
// in the array a with length len
// require: a is not NULL and of length >= len, len >= 0
int count_pos(int a[], int len){
    assert(a != NULL);
    int count = 0;
    for (int i = 0; i < len; ++i) {
        if (a[i] > 0) {
            ++count;
        }
    }
    return count;
}
