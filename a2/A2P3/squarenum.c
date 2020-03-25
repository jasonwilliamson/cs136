// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 02, Problem 3
// File: squarenum.c
// ====================================================

#include "squarenum.h"


static bool test_if_square_upto(const int n, const int upper_lim, const int acc);


// see squarenum.h for details
bool is_squarenum(const int i){
    return test_if_square_upto(i, (i/2), 1);
}


// see squarenum.h for details
int next_squarenum(const int i){
    if (test_if_square_upto((i+1), ((i+1)/2), 1)) {
        return (i+1);
    }else{
        return next_squarenum(i+1);
    }
}

// see squarenum.h for details
int count_sqnum(const int a, const int b){
    if ((a+1) < b) {
        if (test_if_square_upto((a+1), ((a+1)/2), 1)) {
            return 1 + (count_sqnum((a+1), b));
        }else{
            return (count_sqnum((a+1), b));
        }
    }else{
        return 0;
    }
}


// test_if_square_upto(n,t) consumes n, an int that represents
// the number to be determined whether or not it is a squared number;
// upper_lim, an int that represents the upper limit of domain values to check;
// acc, an int that represents the accumulative checked values, should be
// initialized at 1, in order to check full domain of values.
// requires: n>1
bool test_if_square_upto(const int n, const int upper_lim, const int acc){
    if (acc<=upper_lim) {
        if (n == (acc*acc))  {
            return true;
        }else{
            return test_if_square_upto(n, upper_lim, (acc + 1));
        }
    }else{
        return false;
    }
}





