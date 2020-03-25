//
//  sort.c
//  A7P0A
//
//  Created by Jason Williamson on 2015-07-02.
//  Copyright (c) 2015 Jason Williamson. All rights reserved.
//

#include <stdio.h>
#include "sort.h"

/////////// char sort ///////////////////
void swap_char( char *a, char *b){
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void quick_sort_char( char a[], int len, int first, int last){
    
    if (last <= first) {
        return; // already sorted.. size is <= 1
    }
    
    char pivot = a[first];
    char pos = last;
    
    for (int i = last; i >= first + 1; --i) {
        if (a[i] >= pivot) {
            swap_char(&a[pos], &a[i]);
            --pos;
        }
    }
    swap_char(&a[first], &a[pos]); // put pivot in correct place
    quick_sort_char(a, len, first, pos-1);
    quick_sort_char(a, len, pos+1, last);
}
///////////////////////////////////////////
/////////// string sort ///////////////////
void swap_str( char *a[], char *b[]){
    char *tmp = *a;
    *a = *b;
    *b = tmp;
}

void quick_sort_str( char *a[], int len, int first, int last){
    
    if (last <= first) {
        return; // already sorted.. size is <= 1
    }
    
    char pivot = *a[first];
    char pos = last;
    
    for (int i = last; i >= first + 1; --i) {
        if (*a[i] >= pivot) {
            swap_str(&a[pos], &a[i]);
            --pos;
        }
    }
    swap_str(&a[first], &a[pos]); // put pivot in correct place
    quick_sort_str(a, len, first, pos-1);
    quick_sort_str(a, len, pos+1, last);
}

/////////// int sort ///////////////////
void swap_int( int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quick_sort_int(int a[], int len, int first, int last){
    
    if (last <= first) {
        return; // already sorted.. size is <= 1
    }
    
    char pivot = a[first];
    char pos = last;
    
    for (int i = last; i >= first + 1; --i) {
        if (a[i] >= pivot) {
            swap_int(&a[pos], &a[i]);
            --pos;
        }
    }
    swap_int(&a[first], &a[pos]); // put pivot in correct place
    quick_sort_int(a, len, first, pos-1);
    quick_sort_int(a, len, pos+1, last);
}

/////////////////////////////////////////////




// sort_int(int a[], int len) sorts the array a
// requires: len >= 0; a is an array of length >= len
// effects: a is sorted in ascending order
// time: O(n log n) where n is len
void sort_int(int a[], int len){
    quick_sort_int(a, len, 0, len - 1);
}


// sort_char(int a[], int len) sorts the array a
// requires: len >= 0; a is an array of length >= len
// effects: a is sorted in ascending ASCII order
// time: O(n log n) where n is len
void sort_char(char a[], int len){
    quick_sort_char(a, len, 0, len-1);
}


// sort_str(char *a[], int len) sorts the array a
//   requires: len >= 0; a is an array of length >= len
//   effects: a is sorted in lexicographic order
//   time: O(m*n*log n), where n is len and
//         m is  the longest string in a
//   (note that this assumes the strings have a constant maximum length)
void sort_str(char *a[], int len){
    quick_sort_str(a, len, 0, len-1);
}
