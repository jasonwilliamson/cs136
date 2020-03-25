// =======================================
// = CS136, W14: Assignment 6, Problem 4 =
// = =================================== =
// = Author: C Master [1337]             =
// =======================================

// Implementation for the C module memgame choice. Provides functions to pick the 
// first and second tile.

#include "memgame-choice.h"

#include <stdio.h>

// See interface (memgame-choice.h).
char pick_first(void) {
  printf("what is your first choice (a..p)? ");
  char c;
  do {
    c = getchar();
  } while ((c < 'a') || (c > 'p'));
  return c;
}

// See interface (memgame-choice.h).
char pick_second(void) {
  printf("what is your second choice (a..p)? ");
  char c;
  do {
    c = getchar();
  } while ((c < 'a') || (c > 'p'));
  return c;
}