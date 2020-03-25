//
//  main.c
//  A4P1
//
//  Created by Jason Williamson on 2015-06-09.
//  Copyright (c) 2015 Jason Williamson. All rights reserved.
//

#include <stdio.h>
#include <assert.h>
#include "fib.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    assert(next_fib() == 1);
    assert(next_fib() == 1);
    assert(next_fib() == 2);
    assert(next_fib() == 3);
    assert(next_fib() == 5);
    assert(next_fib() == 8);
    return 0;
}
