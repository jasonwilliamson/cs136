//
//  main.c
//  A3P2
//
//  Created by Jason Williamson on 2015-05-29.
//  Copyright (c) 2015 Jason Williamson. All rights reserved.
//

#include <assert.h>
#include <stdio.h>
#include "hamming.h"


int main(int argc, const char * argv[]) {
    // insert code here...

    assert(hamming(7,5) == 1);
    printf("Hello, hamming(0, 5) == %d \n", hamming(0, 5));
    assert(hamming(0, 5) == 2);
    return 0;
}
