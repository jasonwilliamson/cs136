// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 07, Problem 4
// File: anagrams.c
// ====================================================
//

#include "anagrams.h"
#include <stdbool.h>
#include "sort.h"


// get_str_length(str) consumes char array pointer (string)
// counting the elements within the array until '\0' is
// reached. Function returns an integer value of the length
// requires: char str[] must be null terminated
int get_str_length(char str[]){
    int len = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        ++len;
    }
    return len;
}


// is_anagrams(str1,str2) consumes two strings and returns
// true if st1 and st2 are anagrams, otherwise returning false
// effects: might change the order of char's in st1, and st2
// time: O(n log n) where n is len
bool is_anagrams(char *st1, char *st2) {
    int len_st1 = get_str_length(st1);
    int len_st2 = get_str_length(st2);
    if (len_st1 == len_st2) {
        sort_char(st1, len_st1);
        sort_char(st2, len_st2);
        for (int i = 0; i < len_st1; ++i) {
            if(st1[i] != st2[i]){
                return false;
            }
        }
    }else{
        return false;
    }
    
    return true;
}



// count_anagrams(*a[], len) consumes an array of strings, and an
// int, len, the length of *a[], function produces the total number of anagram pairs
// within the provided array
// Summation: O(1) + O(n) + O(n log n) where n is len
// time: O(n log n)
int count_anagrams( char * a[], int len ) {
    int total_pairs = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (is_anagrams(a[i], a[j])){
                ++total_pairs;
            }
        }
    }
    return total_pairs;
}