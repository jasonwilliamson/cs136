//
//  main.c
//  A8P0
//
//  Created by Jason Williamson on 2015-07-10.
//  Copyright (c) 2015 Jason Williamson. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "strdup.h"
#include "posn.h"
#include "reservation.h"
#include "readstr.h"
#include <strings.h>

int main(int argc, const char * argv[]) {
    
    char a[] = "I like coffee";
    char *b = my_strdup(a);
    printf("%s\n",b );
    int len = 0;
    while (*b) {
        printf("char == %c\n", *b);
        ++len;
        b++;
        //printf("len == %d\n", len);
    }
    
    // insert code here...
    /*printf("Hello, World!\n");
    
    
    char a[] = "HELLO";
    char *b = my_strdup(a);
    printf("%s\n",b );
    
    struct posn *new_posn = make_posn(5, 10);
    printf(" new_posn.x == %d, .y == %d\n", (*new_posn).x, (*new_posn).y );*/
    
    /*struct manifest *new_m = create_manifest(3, 5);
    printf("sizeof(new_m == %lu\n", sizeof(new_m));
    destroy_manifest(new_m);

    struct manifest *second_m = create_manifest(6, 7);
    printf("sizeof(second_m == %lu\n", sizeof(second_m));
    printf(" huh new_m.fc == %d\n", new_m->num_fc);*/
    
    
   /* char *s = readstr();
    int l = strlen(s);
    if (l > 0) {
        printf("%zd\n%c%c\n",l,s[0],s[l-1]);
    } else {
        printf("0\n{empty string}\n") ;
    }
    free(s);*/
    
    
    
    return 0;
}
