// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 06, Problem 1
// File: reservation.c
// ====================================================
//

#include "reservation.h"
#include <assert.h>
#include <stdlib.h>


// is_valid_manifest(&man) consumes a struct manifest pointer
// and returns true if that manifest meets required assertions
// otherwise throws exception
// requires:  num_fc >= 0, num_ec >= 0, num_fc + num_ec <= 100
static bool is_valid_manifest(struct manifest *man){
    assert(man != NULL);
    assert(man->num_fc >= 0);
    assert(man->num_ec >= 0);
    assert((man->num_ec + man->num_fc) <= 100);
    return true;
}


struct manifest M(int num_fc, int num_ec){
    assert(num_fc >= 0);
    assert(num_ec >= 0);
    assert((num_ec + num_fc) <= 100);
    
    struct manifest new;
    new.num_ec = num_ec;
    new.num_fc = num_fc;
    return new;
}


int get_available_seats_fc(struct manifest *man){
    assert(is_valid_manifest(man));
    int count = 0;
    int fc_seats = man->num_fc;
    for (int i = 0; i < fc_seats; ++i) {
        if (0 == man->seats[i]) {
            ++count;
        }
    }
    return count;
}


int get_available_seats_ec(struct manifest *man){
    assert(is_valid_manifest(man));
    int count = 0;
    int total_seats = (man->num_ec + man->num_fc);
    for (int i = man->num_fc; i < total_seats; ++i) {
        if (0 == man->seats[i]) {
            ++count;
        }
    }
    return count;
}


int book_seat_fc(struct manifest *man){
    assert(is_valid_manifest(man));
    int fc_seats = man->num_fc;
    for (int i = 0; i < fc_seats; ++i) {
        if (0 == man->seats[i]) {
            man->seats[i] = 1;
            return i;
        }
    }
    return -1;
}


int book_seat_ec(struct manifest *man){
    assert(is_valid_manifest(man));
    int total_seats = man->num_ec + man->num_fc;
    for (int i = man->num_fc; i < total_seats; ++i) {
        if (0 == man->seats[i]) {
            man->seats[i] = 1;
            return i;
        }
    }
    return -1;
}


void reset_manifest(struct manifest *man){
    assert(is_valid_manifest(man));
    int total_seats = (man->num_ec + man->num_fc);
    for (int i = 0; i < total_seats; ++i) {
        man->seats[i] = 0;
    }
}



