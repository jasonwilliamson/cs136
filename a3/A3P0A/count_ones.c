// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 03, Problem 0a
// File: count_ones.c
// ====================================================

#include "count_ones.h"
#include <stdio.h>
#include <assert.h>

//static int nth_power_base_2(const int n);
//static int highest_nth_power(const int i, const int acc);

// count_ones(i) Returns the number of 1s in the
//   binary representation of integer i.
// requires: i >= 0
int count_ones(const int i) {
    assert(i >= 0);
    int val = nth_power_base_2(highest_nth_power(i, 1));
    int new_i = i - val;
    
    if (new_i < 0){
        return 0;
    }else if (0 == new_i) {
        return 1;
    }else{
        return 1 + count_ones(new_i);
    }
}


// nth_power_base_2(n) consumes n, an int that represents the power
// with which 2 will be raised. Function returns value of 2^n.
// requires n >= 0
int nth_power_base_2(const int n){
    assert(n >= 0);
    if (0 == n) {
        return 1;
    }else{
        return 2 * (nth_power_base_2(n - 1));
    }
}


// highest_nth_power(n,acc) consumes, i an int that represents
// the value from which we want to extract
// the hightest power of 2 from within that number; consumes acc
// an int accumulator used to store the nth power count. Function
// returns the largest nth power of 2, within i.
int highest_nth_power(const int i, const int acc){
    int val = nth_power_base_2(acc);
    if (val > i) {
        return acc - 1;
    }else if(val == i){
        return acc;
    }else{
        return highest_nth_power(i, (acc + 1));
    }
}




