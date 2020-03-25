// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 08, Problem 4
// File: aos.c
// ====================================================
//

#include "aos.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <strings.h>


// my_strdup(s) makes a duplicate of s and returns a pointer to
// the duplicate char array
// returns NULL if there is not enough memory
// effects: allocates char array on the heap (caller must free)
// time: O(n)
// requires: s != NULL
static char *my_strdup(const char *s) {
    assert(s);
    int str_size = 0;
    while (s[str_size]) {
        ++str_size;
    }
    
    int bytes = (sizeof(char) * (str_size + 1));
    char *new = malloc(bytes);
    
    for (int i = 0; i < str_size; ++i) {
        new[i] = s[i];
    }
    new[str_size] = '\0';
    return new;
}


// see aos.h for details
struct aos *create_aos(int max) {
    int bytes = sizeof(struct aos);
    struct aos *new_aos = malloc(bytes);
    
    bytes = sizeof(char *) * max;
    char **strings_arr = malloc(bytes);
    for (int i = 0; i < max; ++i) {
        strings_arr[i] = NULL;
    }
    
    new_aos->strings = strings_arr;
    new_aos->max = max;
    return new_aos;
}


// see aos.h for details
void destroy_aos(struct aos *a) {
    for (int i = 0; i < a->max; ++i) {
        free(a->strings[i]);
    }
    free(a->strings);
    free(a);
}


// see aos.h for details
int aos_count(struct aos *a) {
    assert(a);
    int count = 0;
    for (int i = 0; i < a->max; ++i) {
        if (NULL != a->strings[i]){
            ++count;
        }
    }
    return count;
}


// see aos.h for details
char *aos_get(struct aos *a, int i) {
    assert(a);
    if ((i < 0) || (i >= a->max)) {
        return NULL;
    }else{
        // strings[i] might still return NULL
        return a->strings[i];
    }
}


// see aos.h for details
void aos_set(struct aos *a, const char *s, int i) {
    assert(a);
    if (NULL != a->strings[i]) {
        free(a->strings[i]);
    }
    a->strings[i] = my_strdup(s);
}


// see aos.h for details
int aos_add(struct aos *a, const char *s) {
    assert(a);
    assert(NULL != s);
    
    for (int i = 0; i < a->max; ++i) {
        if (NULL == a->strings[i]) {
            aos_set(a, s, i);
            return 0;
        }
    }
    return -1;
}


// quick_sort_aos(struct aoc *a, int len, int first, int last)
// sorts the array a->strings
// requires: len >= 0; a->strings is an array of length >= len
// that contains no null elements
// effects: a is sorted in ascending order according to strcmp
// time: O(n log n) or O(n^2)
void quick_sort_aos(struct aos *a, int len, int first, int last){
    
    if (last <= first) {
        return; // already sorted.. size is <= 1
    }
    
    char *pivot = a->strings[first];
    int pos = last;
    
    for (int i = last; i >= first + 1; --i) {
        int val = strcmp(a->strings[i], pivot);
        if (val >= 0) {
            char *s = my_strdup(a->strings[pos]);
            aos_set(a, a->strings[i], pos);
            aos_set(a, s, i);
            free(s);
            --pos;
        }
    }
    // put pivot in correct place
    char *s = my_strdup(pivot);
    aos_set(a, a->strings[pos], first);
    aos_set(a, s, pos);
    free(s);
    quick_sort_aos(a, len, first, pos-1);
    quick_sort_aos(a, len, pos+1, last);
}


// see aos.h for details
void aos_sort(struct aos *a) {
    
    int valid_count = aos_count(a);
    int index = 0;
    int max_index = a->max -1;
    
    while (index < valid_count) {
        if (a->strings[index] == NULL) {
            if (a->strings[max_index] != NULL) {
                aos_set(a, a->strings[max_index], index);
                ++index;
                --max_index;
            }else{
                --max_index;
            }
        }else{
            ++index;
        }
    }
    
    quick_sort_aos(a, valid_count, 0, valid_count - 1);
}

