// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 08, Problem 0a
// File: reservation.c
// ====================================================
//

#include "reservation.h"
#include <assert.h>
#include <stdlib.h>


struct manifest *create_manifest(int num_fc, int num_ec) {
    assert(num_fc >= 0);
    assert(num_ec >= 0);
    assert((num_ec + num_fc) > 0);
    struct manifest *m = malloc(sizeof(struct manifest));
    m->num_fc = num_fc;
    m->num_ec = num_ec;
    m = realloc(m, sizeof(bool)*(num_fc + num_ec));
    m->seats = malloc(sizeof(bool)*(num_fc + num_ec));
    return m;
}


void destroy_manifest(struct manifest *m) {
    assert(m);
    free(m->seats);
    free(m);
}
