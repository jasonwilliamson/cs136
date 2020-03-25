//
//  main.c
//  A6P1
//
//  Created by Jason Williamson on 2015-06-27.
//  Copyright (c) 2015 Jason Williamson. All rights reserved.
//

#include <stdio.h>
#include <assert.h>
#include "reservation.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    struct manifest man = M(2,3);
    assert(get_available_seats_fc(&man) == 2);
    assert(get_available_seats_ec(&man) == 3);
    assert(book_seat_fc(&man) == 0);
    assert(book_seat_ec(&man) == 2);
    
    struct manifest man2 = M(5,8); //13
    assert(get_available_seats_fc(&man2) == 5);
    assert(get_available_seats_ec(&man2) == 8);
    assert(book_seat_fc(&man2) == 0);
    assert(book_seat_fc(&man2) == 1);
    assert(book_seat_fc(&man2) == 2);
    assert(book_seat_ec(&man2) == 5);
    
    return 0;
}
