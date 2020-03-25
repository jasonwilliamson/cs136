// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 04, Problem 5
// File: banking.c
// ====================================================
//

#include "banking.h"


static int total_cents_transferred = 0;
static int total_transactions = 0;

static void update_money_count(int amt);
static void update_transaction_count(void);
static void update_max_deposit(struct bank_acct *acct, int amt);
static void update_max_withdrawal(struct bank_acct *acct, int amt);


// see header file
// requires: new_id > 0, new_bal >= 0
struct bank_acct create_acct(int new_id, int new_bal){
    assert(new_id > 0);
    assert(new_bal >= 0);
    
    struct bank_acct new_acct = {new_id, new_bal,0,0};
    return new_acct;
}


// see header file
void reset_statistics(void) {
    total_transactions = 0;
    total_cents_transferred = 0;
}


// see header file
// requires: acct is not NULL and *acct is a valid account
int get_balance(struct bank_acct *acct) {
    assert(acct != NULL);
    return acct->balance;
}


// see header file
// requires: acct is not NULL and *acct is a valid account
int get_id(struct bank_acct *acct) {
    assert(acct != NULL);
    return acct->_id;
}


// see header file
// requires: acct is not NULL
//           and amt > 0, there is an active account
void deposit(struct bank_acct *acct, int amt) {
    assert(acct != NULL);
    assert(amt > 0);
    acct->balance += amt;
    update_max_deposit(acct, amt);
    update_money_count(amt);
    update_transaction_count();
}


// see header file
// requires:  acct is not NULL, *acct is a valid account
//            amt > 0
bool withdraw(struct bank_acct *acct, int amt) {
    assert(acct != NULL);
    assert(amt > 0);
    if (amt <= acct->balance) {
        acct->balance -= amt;
        update_max_withdrawal(acct, amt);
        update_money_count(amt);
        update_transaction_count();
        return true;
    }else{
        return false;
    }
}


// see header file
// requires: acct is not NULL, *acct is a valid account
int max_withdrawal(const struct bank_acct *acct) {
    assert(acct != NULL);
    return acct->max_withdrawal;
}


// see header file
int max_deposit(const struct bank_acct *acct) {
    assert(acct != NULL);
    return acct->max_deposit;
}


// see header file
int transaction_count(void) {
    return total_transactions;
}

// see header file
int money_count(void) {
    return total_cents_transferred;
}


// see header file
bool wire_transfer(struct bank_acct *to_acct, struct bank_acct* from_acct,  int amt) {
    assert(to_acct != NULL);
    assert(from_acct != NULL);
    assert(amt > 0);
    if (to_acct->_id != from_acct->_id) {
        if (withdraw(from_acct, amt)) {
            // Special case deposit, without adding value to total
            to_acct->balance += amt;
            update_transaction_count();
            update_max_deposit(to_acct, amt);
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}


// update_money_count(amt) consumes amt, an int and adds it to the accumalitve
// sum of total money transferred.
// effects: increments total_cents_transferred by the amt provided
// requires: amt > 0
static void update_money_count(int amt){
    assert(amt > 0);
    total_cents_transferred += amt;
}


// update_transaction_count() increments the transaction count
// by one
// effects: increments total_transactions by one
static void update_transaction_count(void){
    ++total_transactions;
}


// update_max_deposit(*acct, amt) consumes *acct a point of type struct bank_acct
// and amt an it that represents the deposit amount, update max_deposit
// field of the consumed struct bank_acct if acct.max_deposit < amt. Otherwise
// acct is not updated.
// note: if acct.max_deposit == 0, max_deposit is automatically updated
// effects: replaced value of acct's max_deposit if amt > max_deposit
// requires:  acct is not NULL, *acct is a valid account
void update_max_deposit(struct bank_acct *acct, int amt){
    assert(acct != NULL);
    if (0 == acct->max_deposit) {
        acct->max_deposit = amt;
    }else if (amt > acct->max_deposit){
        acct->max_deposit = amt;
    }
}


// update_max(*acct, amt) consumes *acct a pointer of type struct bank_acct, and
// amt an int that represents the withdrawal amount, updating the max_withdrawal
// field of the consumed struct bank_acct if acct.max_withdrawal < amt. Otherwise
// acct is not updated.
// note: if acct.max_withdrawel == 0, max_withdrawel is automatically updated
// effects: replaced value of acct's max_widrawal if amt > max_widrawal
// requires:  acct is not NULL, *acct is a valid account
void update_max_withdrawal(struct bank_acct *acct, int amt){
    assert(acct != NULL);
    if (0 == acct->max_withdrawal) {
        acct->max_withdrawal = amt;
    }else if (amt > acct->max_withdrawal){
        acct->max_withdrawal = amt;
    }
}

