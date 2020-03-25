//
//  main.c
//  A3P5
//
//  Created by Jason Williamson on 2015-05-30.
//  Copyright (c) 2015 Jason Williamson. All rights reserved.
//

#include <stdio.h>
#include "roots.h"
#include <stdbool.h>
#include <assert.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, close_to_zero(0.00001) == %d !\n", close_to_zero(0.0001));
    printf("Hello, close_to_zero(0.00001) == %d !\n", close_to_zero(-0.0001));
    printf("Hello, close_to_zero(0.00001) == %d !\n", close_to_zero(0.0001));
    printf("find_root(1, -8, 15, 2, 4) == %f \n", find_root(1, -8, 15, 2, 4));
    printf("find_root(4, -56, 75, 0.5, 3.0) == %f \n", find_root(4, -56, 75, 0.5, 3.0));
    return 0;
}
