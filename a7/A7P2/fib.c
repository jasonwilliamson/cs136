// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 07, Problem 2
// File: fib.c
// ====================================================
//

// A module that provides the funciton fast_fib(int n); that behaves the
// same as a standard fib function but has a run time of O(n) where n is the
// value of the consumed n.

#include "fib.h"
#include <assert.h>

int fn_1 = 1;
int fn_2 = 1;


// reset_f_values set the values of both fn_1 and fn_2
// to one
// time: O(1)
// effects: set values of both fn_1 and fn_2 to 1;
static void reset_f_values(void){
    fn_1 = 1;
    fn_2 = 1;
}


// fib_generator(n) consumes an int, n, and returns the fibonacci integer
// associated with F sub n. As F sub n = F sub (n - 1) + F sub (n - 2)
// time: O(n)
// effects: might change values of fn_1 and fn_2
// requires: n > 0
static int fib_generator(int n){
    assert(n > 0);
    if ((n == 1) || (n == 2)) {
        return 1;
    }else{
        int tmp = fn_1 + fn_2;
        fn_2 = fn_1;
        fn_1 = tmp;
        return tmp;
    }
}


// fast_fib(n) consumes an int, n, and returns the fibonacci integer
// associated with F sub n. As F sub n = F sub (n - 1) + F sub (n - 2)
// time: O(n)
// requires: n > 0
int fast_fib(int n) {
    assert(n > 0);
    int tmp = 0;
    for (int i = 1; i <= n; ++i) {
        tmp = fib_generator(i);
    }
    reset_f_values();
    return tmp;
}

