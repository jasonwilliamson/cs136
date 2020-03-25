// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 05, Problem 3a
// File: intseq.c
// ====================================================
//

#include "intseq.h"
#include <assert.h>
#include <stdio.h>

// is_valid_sequence(seq, len) consumes a sequence seq, and length of that sequence
// returning true if the consumes seq and len are valid
static bool is_valid_sequence(int seq[], int len){
    assert(seq != NULL);
    assert(len > 0);
    return true;
}

// get_index_of_first_appearance(seq,len,value) consumes a sequence of integers seq,
// along with length of seq's array len, and a value to lookup within the sequence.
// Function returns the index of the first accurance of value with seq, if no occurence
// is found function returns -1;
static int get_index_of_first_appearance(int seq[], int len, int value){
    assert(is_valid_sequence(seq, len));
    for (int i = 0; i < len; ++i) {
        if (value == seq[i]) {
            return i;
        }
    }
    return -1;
}

int number_sum(int seq[], int len) {
    assert(is_valid_sequence(seq, len));
    int sum = 0;
    for (int i = 0; i < len; ++i) {
        sum += seq[i];
    }
    return sum;
}


int max_number(int seq[], int len) {
    assert(is_valid_sequence(seq, len));
    int max_so_far = seq[0];
    for (int i = 1; i < len; ++i) {
        if (max_so_far < seq[i]){
            max_so_far = seq[i];
        }
    }
    return max_so_far;
}


int min_number(int seq[], int len) {
    assert(is_valid_sequence(seq, len));
    int min_so_far = seq[0];
    for (int i = 1; i < len; ++i) {
        if (min_so_far > seq[i]){
            min_so_far = seq[i];
        }
    }
    return min_so_far;
}


int minmax_dist(int seq[], int len) {
    assert(is_valid_sequence(seq, len));
    int max_val = max_number(seq, len);
    int min_val = min_number(seq, len);
    int index_max = get_index_of_first_appearance(seq, len, max_val);
    int index_min = get_index_of_first_appearance(seq, len, min_val);
    if (index_max >= index_min) {
        return (index_max - index_min);
    }else{
        return (index_min - index_max);
    }
    
}


float seq_avg(int seq[], int len) {
    assert(is_valid_sequence(seq, len));
    return (number_sum(seq, len) / len);
}


bool seq_has_duplicates(int seq[], int len) {
    assert(is_valid_sequence(seq, len));
    for (int i = (len - 1); i > 1; --i) {
        if (-1 != get_index_of_first_appearance(seq, (i - 1), seq[i])) {
            return true;
        }
    }
    return false;
}


int seq_most_occurrences(int seq[], int len) {
    assert(is_valid_sequence(seq, len));
    int max_occur = 0;
    int index_of_value = 0;
    int occurence = 0;
    if (!seq_has_duplicates(seq, len)) {
        return seq[0];
    }else{
        for (int i = 0; i < len; ++i) {
            for (int j = 1; j < len; ++j) {
                if (seq[i] == seq[j]) {
                    ++occurence;
                }
            }
            if (occurence > max_occur) {
                max_occur = occurence;
                index_of_value = i;
            }
        }
    }
    return seq[index_of_value];
}


