// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 06, Problem 4
// File: memgame.c
// ====================================================
//

#include "memgame.h"
#include "shuffle.h"
#include <assert.h>

static const int board_size = 16;
static int reveal_count = 0;
static char last_reveal = '\0';
static int last_reveal_index;
char visible_board[board_size];
static char hidden_board[board_size];



// get_index_of_char(arr[], len, c) returns the index value of
// the consumed char c in the consumed char array arr[] of length len.
// Otherwise function returns -1 if no such c is found in arr[].
static int get_index_of_char(char arr[], int len, char c){
    for (int i = 0; i < len; ++i) {
        if (c == arr[i]) {
            return i;
        }
    }
    return -1;
}


// setup_visible_board() populates visible_board[] with
// intitial char values
// effects: fills visible_board[] with char values
static void setup_visible_board(void){
    for (int i = 0; i < board_size; ++i) {
        visible_board[i] = ('a' + i);
    }
}


// setup_hidden_board() populates hidden_board[] with
// initial char values
// effects: fills hidden_board[] with char values
static void setup_hidden_board(void){
    for(int i = 0; i < 8; ++i){
        for (int j = i; j < (i + 2); ++j) {
            hidden_board[(i + j)] = ('0' + i);
        }
    }
}


// Sets the last_reveal value and last_reveal_index
// effects: sets static char last_reveal
//          sets static int last_reveal_index
static void set_last_reveal(char c, int i){
    last_reveal = c;
    last_reveal_index = i;
}


// Returns the last_reveal_index value
static int get_last_reveal_index(void){
    return last_reveal_index;
}


void start_game(void){
    setup_visible_board();
    setup_hidden_board();
    shuffle(hidden_board, board_size);
    reveal_count = 0;
}


char reveal_first(char t){
    assert((t >= 'a') && (t <= 'p'));
    int selected_index = get_index_of_char(visible_board, board_size, t);
    ++reveal_count;
    char c = hidden_board[selected_index];
    set_last_reveal(c, selected_index);
    return c;
}


char reveal_second(char t){
    assert((t >= 'a') && (t <= 'p'));
    int selected_index = get_index_of_char(visible_board, board_size, t);
    ++reveal_count;
    char c = hidden_board[selected_index];
    if ((get_last_reveal() == c) && (selected_index != get_last_reveal_index())) {
        visible_board[selected_index] = c;
        visible_board[get_last_reveal_index()] = c;
    }else{
        set_last_reveal('\0', 0);
    }
    return c;
}


char get_last_reveal(void){
    return last_reveal;
}


int num_reveals(void){
    return reveal_count;
}


bool is_solved(void){
    for (int i = 0; i < board_size; ++i) {
        if (-1 != get_index_of_char(visible_board, board_size, ('a' + i))) {
            return false;
        }
    }
    return true;
}

