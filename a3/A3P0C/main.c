//
//  main.c
//  A3P0C
//
//  Created by Jason Williamson on 2015-05-29.
//  Copyright (c) 2015 Jason Williamson. All rights reserved.
//
#include "gcd.h"
#include <stdio.h>
#include <assert.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    printf("gcd(a, b) == %d \n", gcd(1239, 735));
    assert(gcd(144, 21) == 3);
    assert(gcd(1239, 735) == 21);
    assert(gcd(5406, 4403) == 17);
    
    return 0;
}
