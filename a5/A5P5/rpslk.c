// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 05, Problem 5
// File: rpslk.c
// ====================================================
//

#include "rpslk.h"
#include <stdio.h>
#include <assert.h>

static int player_wins = 0;
static int bot_wins = 0;
static int tie_count = 0;


// get_message(winner, loser) consumes winner and lose both char's
// each representing the challenger who won or lost, i.e. bot or player
// generating a message based on what winner and loser chose to play
void get_message(char winner, char loser){
    if ('s' == winner) {
        if ('p' == loser) {
            printf("Scissors cut paper.");
        }else{
            printf("Scissors decapitate lizard.");
        }
    }else if ('p' == winner){
        if ('r' == loser) {
            printf("Paper covers rock.");
        }else{
            printf("Paper disproves Spock.");
        }
    }else if ('r' == winner){
        if ('l' == loser) {
            printf("Rock crushes lizard.");
        }else{
            printf("Rock crushes scissors.");
        }
    }else if ('l' == winner){
        if ('k' == loser) {
            printf("Lizard poisons Spock.");
        }else{
            printf("Lizard eats paper.");
        }
    }else{
        if ('s' == loser) {
            printf("Spock smashes scissors.");
        }else{
            printf("Spock vaporizes rock.");
        }
    }
}


// see rpslk.h
// requires: player and bot are one of 'r', 'p', 's', 'l', 'k'
int rpslk_winner(char player, char bot) {
    assert(('r' == player)||('p' == player)||('s' == player)||
           ('l' == player)||('k' == player));
    assert(('r' == bot)||('p' == bot)||('s' == bot)||
           ('l' == bot)||('k' == bot));
    
    if ((('r' == player)&&(('p' == bot)||('k' == bot)))||
        (('l' == player)&&(('r' == bot)||('s' == bot)))||
        (('k' == player)&&(('p' == bot)||('l' == bot)))||
        (('s' == player)&&(('r' == bot)||('k' == bot)))||
        (('p' == player)&&(('s' == bot)||('l' == bot))))
    {
        //bot wins
        ++bot_wins;
        get_message(bot, player);
        printf(" ");
        printf("Bot wins!\n");
        return 1;
    }else if ((('r' == bot)&&(('p' == player)||('k' == player)))||
              (('l' == bot)&&(('r' == player)||('s' == player)))||
              (('k' == bot)&&(('p' == player)||('l' == player)))||
              (('s' == bot)&&(('r' == player)||('k' == player)))||
              (('p' == bot)&&(('s' == player)||('l' == player))))
    {
        //player wins
        ++player_wins;
        get_message(player, bot);
        printf(" ");
        printf("Player wins!\n");
        return -1;
    }else{
        //tie
        ++tie_count;
        printf("It's a tie!\n");
        return 0;
    }
        
}


// see rpslk.h
int get_challenge_rating(void) {
    int resp = 0;
    printf("Choose a challenge rating (1 - 1000000): ");
    scanf(" %d",&resp);
    return resp;
}


// see rpslk.h
char get_player_throw(void) {
    char resp;
    printf("What do you throw (r/p/s/l/k)? ");
    while (1) {
        scanf(" %c", &resp);
        if (('r' == resp)||('p' == resp)||('s' == resp)||
            ('l' == resp)||('k' == resp)){
            break;
        }
    }
    return resp;
}


// see rpslk.h
char get_play_again_response(void) {
    char resp;
    printf("Would you like to play again (y/n)? ");
    while (1) {
        scanf(" %c", &resp);
        if (('y' == resp)||('n' == resp)) {
            break;
        }
    }
    return resp;
}


// see rpslk.h
void print_game_summary(void) {
    printf("----- Game Summary -----\n");
    printf("Player won %d rounds...\n", player_wins);
    printf("Bot won %d rounds...\n", bot_wins);
    printf("Player and bot tied %d rounds...\n", tie_count);
    
    if (player_wins > bot_wins) {
        printf("Player wins!\n");
    }else if(player_wins < bot_wins){
        printf("Bot wins!\n");
    }else{
        printf("It's a tie!\n");
    }
}

