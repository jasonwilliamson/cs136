// =======================================
// = CS136, W14: Assignment 6, Problem 4 =
// = =================================== =
// = Author: C Master [1337]             =
// =======================================

// Implementation for the shuffle C module. Provides a function to shuffle an 
// array of chars of any length.

#include "shuffle.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

// Stores whether the PRNG has been seeded or not.
static bool seeded = false;

// See interface (shuffle.h).
void shuffle(char arr[], int len) {
  // Checks pre-conditions.
  assert(arr != NULL);
  assert(len >= 0);

  int to_switch;
  char tmp;

  if (!seeded) {
    srand(1234);

	seeded = true;
  }

  for (int i = 0; i < len; ++i) {
    to_switch = rand() % len;
    tmp = arr[i];
    arr[i] = arr[to_switch];
    arr[to_switch] = tmp;
  }
}
