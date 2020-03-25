//
//  main.c
//  A7P5
//
//  Created by Jason Williamson on 2015-07-05.
//  Copyright (c) 2015 Jason Williamson. All rights reserved.
//

#include <stdio.h>
#include "trinary.h"

int main(int argc, const char * argv[]) {
    // insert code here...
 //   int test = (19%3);
//    printf("19 mod 3 %d \n",test);
//    printf("Hello, %d \n", 5/3);
    int a[] = {6,12,18,22,29,37,38,41,51,53,55,67,73,75,77,81,86,88,94};
    //trinary_search(a, 19, 3);
    //trinary_search(a, 11, 3);
    //trinary_search(a, 9, 3);
    
    
    trinary_search(a, 19, 51);
    
    trinary_search(a, 19, 75);
    
    trinary_search(a, 19, 23);
    
    trinary_search(a, 19, 99);
    return 0;
}
