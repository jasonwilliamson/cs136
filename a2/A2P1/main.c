//
//  main.c
//  A2P1
//
//  Created by Jason Williamson on 2015-05-23.
//  Copyright (c) 2015 Jason Williamson. All rights reserved.
//

#include <stdio.h>
#include "fndivide.h"
#include <assert.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("fndivide(11,5), %d\n", fndivide(11,5));
    printf("fndivide(11,-5), %d\n", fndivide(11,-5));
    assert(fndivide(11,5)==2);
    assert(fndivide(11,-5)==-2);
    return 0;
}
