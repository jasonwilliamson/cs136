// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 04, Problem 2
// File: intseq.c
// ====================================================
//

#include "intseq.h"
//#include <stdio.h>
//#include <assert.h>

struct minmax {
    int value;
    int index;
};

static struct minmax min_num = {0,0};
static struct minmax max_num = {0,0};
static int count_val = 0;
static int prev_num = 0;
static int sum_seq = 0;


static void update_prev_number(const int n);
static void update_number_count(void);
static void update_sum(const int n);
static void update_max(const int n);
static void update_min(const int n);


// see header file
void next_number(int n) {
    update_number_count();
    update_prev_number(n);
    update_sum(n);
    update_min(n);
    update_max(n);
    
}

// see header file
// requires: number_count() > 0
int prev_number(void) {
    assert(number_count() > 0);
    return prev_num;
}

// see header file
int number_count(void) {
    return count_val;
}

// see header file
int number_sum(void) {
    assert(number_count() > 0);
    return sum_seq;
}

// see header file
// requires:  number_count() > 0
int max_number(void) {
    assert(number_count() > 0);
    return max_num.value;
}

// see header file
// requires:  number_count() > 0
int min_number(void) {
    assert(number_count() > 0);
    return min_num.value;
}

// see header file
int minmax_dist(void) {
    assert(number_count() > 0);
    int dist = max_num.index - min_num.index;
    
    if (dist < 0) {
        return -dist;
    }else{
        return dist;
    }
}

// see header file
void reset_seq(void) {
    count_val = 0;
    prev_num = 0;
    sum_seq = 0;
    min_num.value = 0;
    min_num.index = 0;
    max_num.value = 0;
    max_num.index = 0;
    
}


// update_prev_number(n) consumes n, and int and replaces
// the value of previous number with it.
// effects: replaces value in prev_num
void update_prev_number(const int n){
    prev_num = n;
}


// update_number_count() increments the count of numbers
// in the sequence
// effects: increments count_val by one
void update_number_count(void){
    ++count_val;
}


// update_sume(n) consumes n, and int and updates the sum
// by adding n to the accumulative sum.
// effects: increments sum_seq by n;
void update_sum(const int n){
    sum_seq += n;
}


// update_max(n) consumes n, and int and replaces the previous
// max value and its index number in the sequence if n > max
// effects: replaces previous max_num if it is < n
void update_max(const int n){
    if (1 == number_count()) {
        max_num.value = n;
        max_num.index = 1;
    }else if(max_num.value < n){
        max_num.value = n;
        max_num.index = number_count();
    }
}


// update_min(n) consumes n, and int and replaces the previous
// min_value and its index number in the sequence if n < min
// effects: replaces previous min_num if it is > n
void update_min(const int n){
    assert(number_count() > 0);
    if (1 == number_count()) {
        min_num.value = n;
        min_num.index = 1;
    }else if(min_num.value > n){
        min_num.value = n;
        min_num.index = number_count();
    }
    
}




