// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 04, Problem 5
// File: banking.h
// ====================================================
//


#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
/*----------------------------------------------------------------------------
 * This module allows you to perform a series of banking transactions
 * (deposits, withdrawals, and wire transfers) on one or more bank account
 * structures, and keeps track of relevant statistics
 *----------------------------------------------------------------------------*/


struct bank_acct{
    int _id;
    int balance;
    int max_withdrawal;
    int max_deposit;
};

// create_acct(new_id,new_bal) Returns a bank account (bank_acct structure)
//   with the provided id and balance in cents.
// requires: new_id > 0, new_bal >= 0
struct bank_acct create_acct(int new_id, int new_bal);


// reset_statistics() resets all module statistics
// effects: module statistics are reset to initial conditions
//          account specific statistics are unchanged.
void reset_statistics();


// get_balance(acct) Returns the account balance for acct
// requires: acct is not NULL and *acct is a valid account
int get_balance(struct bank_acct *acct);


// get_id(acct) Returns the account id for acct
// requires: acct is not NULL and *acct is a valid account
int get_id(struct bank_acct *acct);


// deposit(acct,amt) Deposits amt cents to the account acct
// requires: amt > 0, there is an active account
// effects: internal statistics may be updated
//          *acct is updated
void deposit(struct bank_acct *acct, int amt);


// withdraw(acct,amt) Attempts to remove amt cents from the account acct
// If the balance is not great enough, the transaction does not complete
// (no money is withdrawn, and this does not count as a transaction).
// Returns whether or not the transaction completed succesfully.
// requires:  acct is not NULL, *acct is a valid account
//            amt > 0
// effects:  internal statistics may be updated
//           *acct may be updated
bool withdraw(struct bank_acct *acct, int amt);


// max_withdrawl(acct) Returns the largest successful withdrawal made from acct
// Returns 0 if there have been no successful withdrawals
// requires: acct is not NULL, *acct is a valid account
int max_withdrawal(const struct bank_acct *acct);


// max_deposit(acct) Returns the largest deposit made to acct
// Returns 0 if there have been no deposits.
// requires: acct is not NULL, *acct is a valid account
int max_deposit(const struct bank_acct *acct);


// transaction_count() Returns the number of successful transactions since
// the program started (this should be reset by reset_statistics)
int transaction_count(void);

// money_count() returns the total number of cents that have been moved
// since the program started (this should be reset by reset_statistics)
int money_count(void);


// wire_transfer(to_acct,from_acct,amt) attempts to transfer amt cents from from_acct into
// to_acct.
// returns true if the transaction completes, and false otherwise.
// Note: The transaction completes if from_acct has a balance of at least amt, and
//       if from_acct and to_acct are different accounts.
// Note: A successful wire transfer of 500 cents counts as 2 transactions
//       (a withdrawl and a deposit) but only counts as a money movement
//       of 500 cents, not 1000.
// requires: amt > 0, from_acct and to_acct are not NULL,
//           *from_acct and *to_acct are valid accounts
bool wire_transfer(struct bank_acct *to_acct, struct bank_acct* from_acct, int amt);


