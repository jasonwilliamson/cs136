//
//  main.c
//  A8P1
//
//  Created by Jason Williamson on 2015-07-12.
//  Copyright (c) 2015 Jason Williamson. All rights reserved.
//

#include <stdio.h>
#include "strappend.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    //printf("Hello, World!\n");
    
    char *string1 = "Hey bob";
    char *string2 = "hoe bob";
    char *new = strappend(string1, string2);
    printf("new == %s", new);
    
    
    return 0;
}
