// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 05, Problem 2
// File: mtable.c
// ====================================================
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static bool is_set = false;
static int y = 0;
static int z = 0;
static int ans = 0;
static int correct_count = 0;
static int incorrect_count = 0;

static void step1(void);
static void step2(void);
static void step3(void);
static void step4(void);
static void step5(void);
static void step6(void);


// set_seed() will initialize a seed value for
// srand() only once.
void set_seed(void) {
    if (!is_set) {
        is_set = true;
        srand(1234);
    }
}


// step1() generates a multiplication problem
static void step1(void){
    y = ((rand() % 11) + 1);
    z = ((rand() % 11) + 1);
    
    printf("%d X %d = ",y,z);
    scanf("%d", &ans);
    
    if (ans != (y*z)) {
        step2();
    }else{
        step4();
    }
}


// step2() handles when first guess is incorrect
static void step2(void){
    int r = rand() % 3;
    if (0 == r) {
        printf("Incorrect.\n");
    }else if (1 == r){
        printf("That is not right.\n");
    }else{
        printf("That is wrong.\n");
    }
    
    printf("Try again: %d X %d = ",y,z);
    scanf("%d", &ans);
    
    if (ans != (y*z)) {
        step3();
    }else{
        step4();
    }
}


// step3() handles second guess is incorrect
static void step3(void){
    ++incorrect_count;
    printf("Sorry. The correct answer is %d X %d = %d\n", y, z, (y*z));
    step5();
}


// step4() handles correct response
static void step4(void){
    ++correct_count;
    int r = rand() % 3;
    if (0 == r) {
        printf("Give me five!\n");
    }else if (1 == r){
        printf("Keep up the good work!\n");
    }else{
        printf("Way to go!\n");
    }
    step5();
}


// step5() prompts user for continue?
static void step5(void){
    printf("Would you like to continue (y/n)? ");
    char y = 'y';
    char n = 'n';
    char resp;
    
    while (1) {
        scanf(" %c", &resp);
        if ((resp == y) || (resp == n)) {
           break;
        }
    }
    if (y == resp) {
        step1();
    }else{
        step6();
    }
}


// step6() handles gameover
static void step6(void){
    float cc = correct_count;
    float ic = incorrect_count;
    float percent = (cc / (cc + ic)) * 100;

    printf("----- Session Summary -----\n");
    printf("Correct answers: %d\n", correct_count);
    printf("Incorrect answers: %d\n", incorrect_count);
    printf("Percentage correct: %.2f%%\n", percent);
}

int main() {
    set_seed();
    step1();
}