// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 08, Problem 5
// File: atree.c
// ====================================================
//

#include "atree.h"
#include <stdlib.h>
#include <assert.h>

const int EMPTY = INT_MIN;


// exp2(n) consumes a int and evaluates 2^n
// returning its value
// requires: n > 0
// time: O(n)
static int exp2(int n) {
    int value = 2;
    while (n > 1) {
        value *= 2;
        --n;
    }
    return value;
}


// is_index_valid(atr, k) consumes struct atree pointer, atr, and k an
// int that represents an index. Function returns true if the index k is
// within the bounds of atr->data's array. Otherwise returning falsel
// time: O(1)
// requires: atr is non null
//           k > 0
static bool is_index_valid(struct atree *atr, int k) {
    assert(atr);
    assert(k > 0);
    int len = exp2(atr->maxheight);
    if (k > len) {
        return false;
    }else{
        return true;
    }
}


// increase_data(atr, k) consumes struct atree pointer, atr, and k, an int
// value that represents a tree height. Function increases atr->data.
// time: O(2^n), where n = k
// effects: increases atr data array
// requires: atr must be non null
//           k > 1
static void increase_data(struct atree *atr, int k) {
    assert(atr);
    assert(k > 1);
    int len = exp2(atr->maxheight);
    struct atree *t = create_atree(k);
    for (int i = 0; i < len; ++i) {
        t->data[i] = atr->data[i];
    }
    free(atr->data);
    atr->data = t->data;
    free(t);
    
}


// see atree.h for details
struct atree *create_atree(int maxheight) {
    
    int size = exp2(maxheight);
    int bytes = sizeof(int) * size;
    int *data = malloc(bytes);
    for (int i = 0; i < size; ++i) {
        data[i] = EMPTY;
    }
    bytes = sizeof(struct atree);
    struct atree *t = malloc(bytes);
    t->data = data;
    t->maxheight = maxheight;
    return t;
}


// see atree.h for details
void destroy_atree(struct atree *atr) {
    free(atr->data);
    free(atr);
}


// see atree.h for details
void atree_add(struct atree *atr, int i) {
    int k = 0;
    int h = 0;
    while (true) {
        
        // node is empty
        if (atr->data[k] == EMPTY) {
            atr->data[k] = i;
            break;
            
        // value aready exists
        }else if (atr->data[k] == i) {
            break;
        
        // search left value
        }else if (atr->data[k] > i) {
            if(!is_index_valid(atr, (2*k + 1))){
                increase_data(atr, h+1);
            }
            k = 2*k + 1;
            h += 1;
            continue;
        
        // search right value
        }else if (atr->data[k] < i) {
            if(!is_index_valid(atr, (2*k + 2))){
                increase_data(atr, h+1);
            }
            k = 2*k + 2;
            h += 1;
            continue;
        }
    }
    
}


// see atree.h for details
bool atree_search(struct atree *atr, int i) {
    int k = 0;
    while (true) {

        // tree is empty
        if (atr->data[k] == EMPTY) {
            return false;
            
        // node is found
        }else if (atr->data[k] == i) {
            return true;
        
        // search left
        }else if (atr->data[k] > i) {
            k = 2*k + 1;
            if (k > exp2(atr->maxheight)) {
                return false;
            }
            continue;
            
        // search right
        }else{
            k = 2*k + 2;
            if (k > exp2(atr->maxheight)) {
                return false;
            }
            continue;
        }
        
        
    }
    return false;
}


