//
//  main.c
//  A2P2
//
//  Created by Jason Williamson on 2015-05-23.
//  Copyright (c) 2015 Jason Williamson. All rights reserved.
//

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

// erase
#include "is_palindrome.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    /*printf("Count 6, 6 == %d \n", (count_digits(6)));
    printf("Count 131 == %d \n", (count_digits(131)));
    printf("Count 123456789, 9 == %d \n", (count_digits(123456789)));
    printf("first digit, 54321, 5 == %d \n", (first_digit(54321)));
    printf("last digit, 54321, 1 == %d \n", (last_digit(54321)));
    printf("10^n 10^4 == %d \n", (nth_power_of_ten(4)));
    printf("remove first and last, 131, 3 == %d \n", remove_first_last_digit(131));
    //printf("palindrome %d \n", (131 - (first_digit(131) * (nth_power_of_ten (count_digits(131) -1)))));*/
    
    printf("is_palindrome(131) %d \n", is_palindrome(131));
    assert(is_palindrome(6)==true);
    assert(is_palindrome(131)==true);
    assert(is_palindrome(123329)==false);
    assert(is_palindrome(123454321)==true);
    return 0;
}
