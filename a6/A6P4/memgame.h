// =======================================
// = CS136, S14: Assignment 6, Problem 4 =
// = =================================== =
// = Author: C Master [1337]             =
// =======================================

// Interface for the memgame C module. Provides functions to play the memory
// game.

#include <stdbool.h>

// Stores the public board (visible to the player).
// e.g., {'a', 'b', 'c', 'd', ... }
// after pairs have been found, will contain their symbols
// e.g., {'3', 'b', '3', 'd', ... }
extern char visible_board[16];

// start_game() starts a new game and shuffles the symbols.
// effects: shuffles the secret board (call shuffle: see shuffle.h)
//       sets the number of reveals to be zero.
void start_game(void);

// reveal_first(t) reveals the symbol at position t.
// requires:  t is a valid tile position ('a', 'b', .... 'p')
// effects: increments the number of reveals
char reveal_first(char t);

// reveal_second(t) reveals the symbol at position t.
// requires:  t is a valid tile position ('a', 'b', .... 'p')
// effects: increments the number of reveals
//       if symbol matches the symbol from previous reveal_first, updates visible_board
//         (note: visible_board is only updated if reveal_first(x) == reveal_second(y) and x != y)
char reveal_second(char t);

// get_last_reveal() returns the most recently revealed symbol. If nothing has been
//       revealed, return '\0'.
char get_last_reveal(void);

// num_reveals() returns the total number of reveals so far.
int num_reveals(void);

// is_solved() returns true if the all of the symbols are visible.
bool is_solved(void);

