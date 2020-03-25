// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 10, Problem 2a
// File: count.c
// ====================================================
//

#include "count.h"
#include <stdlib.h>
#include <stdio.h>


struct count{
    int *arr;
    int len;
};


// see count.h for details
Count create_Count(void){
    const int fixed_size = 101;
    Count new_count = malloc(sizeof(struct count));
    new_count->arr = malloc(sizeof(int) * fixed_size);
    for(int i = 0; i < 101; ++i){
        new_count->arr[i] = 0;
    }
    new_count->len = fixed_size;
    return new_count;
}


// see count.h for details
void destroy_Count(Count c){
    free(c->arr);
    free(c);
}


// see count.h for details
void next(Count c, int i){
    c->arr[i] += 1;
    // store next count at index 0
    c->arr[0] += 1;
}


// see count.h for details
int total(Count c){
    return c->arr[0];
}


// see count.h for details
int unique(Count c){
    int len = c->len;
    int count = 0;
    for (int i = 1; i < len; ++i) {
        if (c->arr[i] > 0) {
            ++count;
        }
    }
    return count;
}


// see count.h for details
int count(Count c, int i){
    return c->arr[i];
}


// see count.h for details
int mostfreq(Count c){
    int len = c->len;
    int max = 0;
    int index = 0;
    for (int i = 1; i < len; ++i) {
        if (c->arr[i] > max) {
            max = c->arr[i];
            index = i;
        }
    }
    return index;
}


// see count.h for details
void stats(Count c){
    int len = c->len;
    for (int i = 1; i < len; ++i) {
        if (c->arr[i] > 0) {
            printf("%d: %d\n", i, count(c,i));
        }
    }
}

