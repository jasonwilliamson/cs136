//
//  main.c
//  A3P4
//
//  Created by Jason Williamson on 2015-05-30.
//  Copyright (c) 2015 Jason Williamson. All rights reserved.
//

#include <stdio.h>
#include <assert.h>
#include "choose.h"
#include <limits.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    assert(choose(7, 3) == 35);
   // printf("Hello, choose(19, 14) == %d \n",choose(19, 14));
    assert(choose(8, 5) == 56);
   // printf("Hello, factorial(n) / (factorial(r) * (factorial(n - r))) == %d / %d \n", factorial(52),
   //        (factorial(52) * (factorial(52 - 5))));
   // assert(choose(52, 5) == 2598960);
    printf("Hello, INT_MAX %d \n", INT_MAX);
    return 0;
}
