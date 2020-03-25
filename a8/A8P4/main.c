//
//  main.c
//  A8P4
//
//  Created by Jason Williamson on 2015-07-14.
//  Copyright (c) 2015 Jason Williamson. All rights reserved.
//

#include <stdio.h>
#include "aos.h"
#include <assert.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    struct aos *a = create_aos(10);
    assert(aos_get(a,5) == NULL);
    aos_set(a,"apple",5);
    assert(strcmp(aos_get(a,5),"apple") == 0);
    assert(aos_add(a,"zebra") == 0);
    aos_sort(a);
    assert(strcmp(aos_get(a,0),"apple") == 0);
    assert(strcmp(aos_get(a,1),"zebra") == 0);
    destroy_aos(a);
    //printf(" strcmp %d\n",strcmp("apple", "zebra"));
    return 0;
}
