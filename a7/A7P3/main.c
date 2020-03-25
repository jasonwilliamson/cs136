//
//  main.c
//  A7P3
//
//  Created by Jason Williamson on 2015-07-05.
//  Copyright (c) 2015 Jason Williamson. All rights reserved.
//

#include <stdio.h>
#include "exp.h"

int main(int argc, const char * argv[]) {
    // insert code here...
   
    printf("2^3 == %d \n",fast_exp(2, 3));
    printf("2^3 == %d \n",fast_exp(3, 10));
    return 0;
}
