// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 04, Problem 1
// File: fib.c
// ====================================================
//

#include "fib.h"


static const int F_1 = 1;
static const int F_2 = 1;
static int fib_count = 0;
static int F_n_sub1 = 1;
static int F_n_sub2 = 1;

static int fib(int n);

// see header file
int next_fib(void) {
    ++fib_count;
    return fib(fib_count);
}


// fib(n) consumes n, an int that represents the seed value
// of a fibonacci number, producing the value of that number
// within the fibonacci sequence.
// effects: values of the sequence are incremented each call
int fib(int n) {
    if (1 == n) {
        return F_1;
    }else if (2 == n) {
        return F_2;
    }else{
        int tmp = F_n_sub2;
        F_n_sub2 = F_n_sub1;
        F_n_sub1 = tmp + F_n_sub2;
        return F_n_sub1;
    }
}

