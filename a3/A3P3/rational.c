// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 03, Problem 3
// File: rational.c
// ====================================================
//

#include "rational.h"


static int gcd(const int a, const int b);
static struct rational r_reduced(struct rational a);
struct rational r_neg_pos(struct rational a);


// see header
struct rational R(int n, int d) {
    // NOTE: we will see later why this is rarely done in C.
    //   However, for now we will do this to make your code
    //   easier to program and test
    const struct rational r = {n, d};
    return r;
}


// see header
struct rational r_add(struct rational a, struct rational b) {
    int common_num_a = a.num * b.den;
    int common_num_b = b.num * a.den;
    int common_den = a.den * b.den;
    return r_reduced(R((common_num_a + common_num_b), common_den));
}


// see header
struct rational r_sub(struct rational a, struct rational b) {
    int common_num_a = a.num * b.den;
    int common_num_b = b.num * a.den;
    int common_den = a.den * b.den;
    return r_reduced(R((common_num_a - common_num_b), common_den));
}


// see header
struct rational r_mult(struct rational a, struct rational b) {
    return r_reduced(R((a.num * b.num), (a.den * b.den)));
}


// see header
struct rational r_div(struct rational a, struct rational b) {
    return r_reduced(R((a.num * b.den), (a.den * b.num)));
}


// see header
bool r_equal(struct rational a, struct rational b) {
    assert(a.den >= 1);
    assert(b.den >= 1);
    if ((a.den == b.den) && (a.num == b.num)) {
        return true;
    }else{
        return false;
    }
}


// r_reduced(a) consumes a, a struct and produces a fully
// reduced rational, following *rules for simplifying rationals, see
// header for details on rules
struct rational r_reduced(struct rational a){
    struct rational a_new = r_neg_pos(a);
    int r_gcd = gcd(a_new.num, a_new.den);
    if (1 == r_gcd){
        return a_new;
    }else{
        return R((a_new.num / r_gcd),(a_new.den / r_gcd));
    }
}


// r_neg_pos(a) consumes a, a struct and produces a
// struct such that the den cannot be negative.
// example (-1/-2) -> (1 / 2)
//         (1/-2) -> (-1 / 2)
struct rational r_neg_pos(struct rational a){
    // both negative
    if ((a.num < 0) && (a.den < 0)){
        return R(-a.num, -a.den);
    // den is neg
    }else if((a.num >= 0) && (a.den < 0)){
        return R(-a.num, -a.den);
    }else{
        return a;
    }
}


// gcd(a,b) Finds the greatest common divisor of a and b.
int gcd(const int a, const int b) {
    if (0 == b) {
        return a;
    }else{
        return gcd(b, (a % b));
    }
}




