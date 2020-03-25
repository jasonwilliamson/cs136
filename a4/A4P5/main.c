//
//  main.c
//  A4P5
//
//  Created by Jason Williamson on 2015-06-09.
//  Copyright (c) 2015 Jason Williamson. All rights reserved.
//

#include <stdio.h>
#include "banking.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    struct bank_acct ba1 = create_acct(123456789,0);
    struct bank_acct ba2 = create_acct(987654321,100);
    deposit(&ba1,30);
    withdraw(&ba1,20);
    
    assert(get_balance(&ba1) == 10);
    assert(max_withdrawal(&ba1) == 20);
    assert(max_deposit(&ba1) == 30);
    assert(transaction_count() == 2);
    
    deposit(&ba2,100);
    wire_transfer(&ba2,&ba1, 10);
    assert(get_balance(&ba2) == 210);
    assert(max_withdrawal(&ba2) == 0);
    
    
    assert(max_deposit(&ba2) == 100);
    assert(transaction_count() == 5);
    assert(max_withdrawal(&ba1) == 20);
    deposit(&ba1, 500);
    withdraw(&ba1, 21);
    assert(max_withdrawal(&ba1) == 21);
    printf("Hello, total_cents?? %d \n", money_count());
    reset_statistics();
    printf("Hello, total_cents?? %d \n", money_count());
    return 0;
}
