// =======================================
// = CS136, W14: Assignment 6, Problem 4 =
// = =================================== =
// = Author: C Master [1337]             =
// =======================================

// Implementation for the C module game I/O. Provides a function for players to 
// interactively play the memory game.

#include "game-io.h"

#include <stdbool.h>
#include <stdio.h>

#include "memgame.h"
#include "memgame-choice.h"

// print_visible_board() outputs the visible board.
// effects: outputs the visible board to the player.
static void print_visible_board(void) {
   const int max_rows = 4;
   const int max_cols = 4;

   for (int row = 0; row < max_rows + 2; ++row) {
      for (int col = 0; col < max_cols + 2; ++col) {
         if ((row == 0) || (row == max_rows + 1)) {
            if (col == 0) {
               printf("+");
            } else if (col == max_cols + 1) {
               printf("--+");
            } else {
               printf("---");
            }
         } else if (col == 0) {
            printf("|");
         } else if (col == max_cols + 1) {
            printf("  |");
         } else {
            printf("%3c", visible_board[((row - 1) * max_cols) + (col - 1)]);
         }
      }

      printf("\n");
   }
}

// See interface (game-io.h).
void interactive_game(void) {
   start_game();
   
   // Iterates until the game is won.
   while (!is_solved()) {
      print_visible_board();
      
      char f = pick_first();
      printf("The symbol revealed is: %c\n", reveal_first(f));
      
      char s = pick_second();
      printf("The symbol revealed is: %c\n", reveal_second(s));
   }
   
   printf("You required %d reveals to solve the game!\n", num_reveals());
}
