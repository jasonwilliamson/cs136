//
//  main.c
//  A7P2
//
//  Created by Jason Williamson on 2015-07-04.
//  Copyright (c) 2015 Jason Williamson. All rights reserved.
//

#include <stdio.h>
#include "fib.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    /*int tmp;
    for (int i = 1; i < 14; ++i) {
        tmp = fast_fib(i);
        printf("fib(%d) == %d \n", i, tmp);
    }*/
    
    printf("fib(%d) == %d \n", 10,fast_fib(10));
        printf("fib(%d) == %d \n", 14,fast_fib(14));
   
    return 0;
}
