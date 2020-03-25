//
//  main.c
//  A8P2
//
//  Created by Jason Williamson on 2015-07-12.
//  Copyright (c) 2015 Jason Williamson. All rights reserved.
//

#include <stdio.h>
#include "afilter.h"
#include <stdlib.h>

//printf("Hello, World!\n");
bool functionA(int i){
    if (i != 0){
        return true;
    }else{
        return false;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    
    //int *arr[8] = {1,0,1,0,1,1,1,1};
    int bytes = sizeof(int) * 8;
    int * arr = malloc(bytes);
    //int *new = arr;
    for (int i = 0; i < 8; ++i) {
        arr[ i ] = i % 2;
        printf("arr[i] == %d\n", arr[i]);
    }
    struct dyn_array * d = malloc(sizeof(struct dyn_array));
    d->data = arr;
    d->len = 8;
    d->max = 10;
    afilter(d, functionA);
    
    for (int j = 0; j < d->len; ++j) {
        printf("new arr[j] == %d\n", d->data[j]);
    }
    return 0;
}
