//
//  main.c
//  A4P0A
//
//  Created by Jason Williamson on 2015-06-09.
//  Copyright (c) 2015 Jason Williamson. All rights reserved.
//

#include <stdio.h>
#include "swap.h"
#include <assert.h>


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    struct posn a = {3, 4};
    struct posn b = {5, 6};
    swap(&a, &b);
    assert(a.x == 5);
    assert(a.y == 6);
    assert(b.x == 3);
    assert(b.y == 4);
    printf("Hello, a.x == %d , a.y == %d \n", a.x, a.y);
    
    return 0;
}
