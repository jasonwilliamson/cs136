

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

// erase
//#include "palindrome.h"
#include "palindrome.h"
#include "exponent.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Count 6, 6 == %d \n", (count_digits(6)));
    printf("Count 131 == %d \n", count_digits(131));
     printf("Count 123456789, 9 == %d \n", (count_digits(123456789)));
     printf("first digit, 54321, 5 == %d \n", (first_digit(54321)));
     printf("last digit, 54321, 1 == %d \n", (last_digit(54321)));
     printf("10^n 10^4 == %d \n", (nth_power_of_ten(4)));
     printf("remove first and last, 131, 3 == %d \n", remove_first_last_digit(131));
    printf("remove first and last, 1313782731, 31378273 == %d \n", remove_first_last_digit(1313782731));
     //printf("palindrome %d \n", (131 - (first_digit(131) * (nth_power_of_ten (count_digits(131) -1)))));
    printf("HELLO HELLO HELLO \n");
    printf("exponent(2, 3) == %d \n",exponent(2, 3));
    //
    
    printf("Count 131 == %d \n", 13);
    printf("is_palindrome(131) %d \n", is_palindrome(131));
    printf("is one %d \n", is_palindrome(313));
     printf("is ??? %d \n", is_palindrome(123454321));
    assert(is_palindrome(6)==true);
    assert(is_palindrome(131)==true);
    assert(is_palindrome(123329)==false);
    assert(is_palindrome(123454321)==true);
    
    
    
    
    return 0;
}
