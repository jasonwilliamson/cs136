// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 07, Problem 5
// File: trinary.c
// ====================================================
//

#include "trinary.h"
#include <stdbool.h>
#include <assert.h>

static int comparison_count = 0;
static int ind1, ind2 = 0;
static int index_zero = 0;
static bool success = false;


// trinary_comparison_trace() displays necessary message for total
// comparisons made
// effects: displays a message, changes comparison_count value
// time: O(1)
void trinary_comparison_trace(){
    printf("A total of %d comparisons were made\n", comparison_count);
    comparison_count = 0;
}


// trinary_equal_trace(num, value) consumes num and value both int's
// displays necesary message for an equality check
// effects: displays a message
// time: O(1)
void trinary_equal_trace(int num, int value){
    printf("Checking if %d is equal to %d\n", value, num);
}


// trinary_less_trace(num, value) consumes num and value both int's
// displays necesary message for a strictly less than check
// effects: displays a message
// time: O(1)
void trinary_less_trace(int num, int value){
    printf("Checking if %d is less than %d\n", value, num);
}


// trinary_success_trace(num, value) consumes num and value both int's
// displays necesary message for a success case
// effects: displays a message, changes comparison_count and
//          success values
// time: O(1)
void trinary_success_trace(int index, int value){
    printf("Search successful\n");
    printf("%d is located at index %d\n", value, index);
    trinary_comparison_trace();
    comparison_count = 0;
    success = true;
}


// set_index_values(first, last) consumes first and last, both int's.
// first represents the first index, and last represents the last. This
// function divides the length of (last - first) into three regions, separated
// by two index markers, ind1 and ind2.
// note: if possible the regions will be equal, otherwise then the size of
// then the size of region 1 will be greater than or equal to the size
// of region 2, and the size of region 2 will be greater than or equal to
// the size of region 3. The size of any two regions will differ by at most
// one.
// effects: changes values of ind1 and ind2;
// time: O(1)
void set_index_values(int first, int last){
    int n = last - first;
    if ((n % 3) == 0) {
        ind1 = n/3 + first;
        ind2 = ind1 + n/3;
    }else if ((n % 3) == 1) {
        ind1 = (n / 3) + first;
        ind2 = ind1 + 1 + ind1;
    }else{
        ind1 = (n / 3) + 1 + first;
        ind2 = ind1 + 1 + (n / 3);
    }
}


// see interface
void trinary_search(int *a, int n, int v) {
    assert(a != NULL);
    set_index_values(0, n);
    index_zero = 0;
    success = false;
    
    for (int i = 0; i < n; ++i) {
        
        if ((n - index_zero) <= 4) {
            for (int j = index_zero; j < n; ++j) {
                ++comparison_count;
                trinary_equal_trace(a[j], v);
                if (a[j] == v) {
                    trinary_success_trace(j, v);
                }
            }
        }else{
            
            ++comparison_count;
            trinary_equal_trace(a[ind1], v);
            if (a[ind1] == v) {
                trinary_success_trace(ind1, v);
                break;
            }
            
            // trinary_search with region 1
            ++comparison_count;
            trinary_less_trace(a[ind1], v);
            if (v < a[ind1]) {
                i = index_zero;
                n = ind1;
                if ((n - i) > 4) {
                    set_index_values(index_zero,ind1);
                }
                continue;
            }
            
            ++comparison_count;
            trinary_equal_trace(a[ind2], v);
            if (a[ind2] == v){
                trinary_success_trace(ind2, v);
                break;
            }
            
            // trinary_seearch with region 2
            ++comparison_count;
            trinary_less_trace(a[ind2], v);
            if (v < a[ind2]){
                i = ind1;
                n = ind2;
                index_zero = ind1 + 1;
                if ((n - i) > 4) {
                    set_index_values((ind1+1), ind2);
                }
                continue;
                
            // trinary_seearch with region 3
            }else{
                i = ind2;
                index_zero = ind2 + 1;
                if ((n - i) > 4) {
                    set_index_values(ind2, n);
                }
                continue;
            }
        }
    }
    
    if (!success) {
        printf("Seach not successful\n");
        trinary_comparison_trace();
    }
}
