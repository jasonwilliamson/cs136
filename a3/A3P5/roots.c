// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 03, Problem 5
// File: roots.c
// ====================================================
//


#include "roots.h"
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>

//static float f(float a, float b, float c, float x);
//static float x_mid(float p, float q);
//bool close_to_zero(float y);
float avg_of_2(float p, float q);
static const float zero_approx = 0.000012;


// find_root(a,b,c,p,q) Finds the root of f(x)=ax^2+bx+c,
//   located in the range [p,q] inclusive.
// requires: there is only one root of f in [p,q]
//           p <= q
float find_root(float a, float b, float c, float p, float q) {
    float y_0 = f(a, b, c, p);
    float y_1 = f(a, b, c, q);
    float x_mid = avg_of_2(p, q);
    float y_mid = f(a, b, c, x_mid);
    if (close_to_zero(y_0) && close_to_zero(y_1) ) {
        return p;
    }else if ((y_mid > 0) && (y_0 > 0)){
        return (find_root(a, b, c, x_mid, q));
    }else{
        return find_root(a, b, c, p, x_mid);
    }
}


// close_to_zero(y) consumes y, a float and produces true
// if that y value is within a pre determined range close
// to 0. Otherwise function returns false.
bool close_to_zero(float y){
    if ((y <= 0) && (y >= -zero_approx)) {
        return true;
    }else if ((y >= 0) && (y <= zero_approx)){
        return true;
    }else{
        return false;
    }
}


// f(a,b,c,x) consumes a,b,c,x all floats and calculates
// the output for a quadratic function of the form
// f(x)=a*x*x+b*x+c.
float f(float a, float b, float c, float x){
    return a*x*x+b*x+c;
}


// avg_of_2(p,q) consumes p, q, both floats and produces the
// average of the two values.
float avg_of_2(float p, float q){
    return (p + q) / 2;
}

