// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 08, Problem 2
// File: afilter.c
// ====================================================
//

#include "afilter.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


// see afilter.h for details
void afilter(struct dyn_array *da, bool (*f)(int)) {
    assert(da);
    assert(da->len <= da->max);
    
    int bytes = sizeof(int) * da->len;
    int *new_da = malloc(bytes);
    int new_index = 0;
    int i = 0;
    
    while (i < da->len) {
        if (f(da->data[i]) == true) {
            new_da[new_index] = da->data[i];
            ++new_index;
        }
        ++i;
    }
    bytes = sizeof(int) * new_index;
    new_da = realloc(new_da, bytes);
    free(da->data);
    da->data = new_da;
    da->len = new_index;
}