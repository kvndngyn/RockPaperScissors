
/**
 *A simple rock, paper scissors game using RNG. It uses custom functions.
 *
 *@author Nguyen, Kevin
 *@assignment ICS 212 Assignment 09
 *@date 3 October 2019
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void score();
void results();
char getComputerChoice();
int player = 0;
int computer = 0;
int tie = 0;
char playerChoice = ' ';
char computerChoice = ' ';
int flag = 0;

int main(){
  //Lets player know the game and how to quit.
  printf("Welcome to the rock-paper-scissors game!\nTo quit the game, press Q or q and enter\n");

  while (flag == 0){
  //Lets player know what to input.
  printf("Enter 'r', 'p', or 's' for rock, paper, scissors: ");
  playerChoice = getchar(); //Gets player's choice
  computerChoice = getComputerChoice(); //Gets computer's choice
  results(); //Compares choices to get result
  getchar(); //Clear buffer
  printf("\n");
  }
  score(); //Displays score
  return 0;
}

/**
 *Displays score of the player, computer, and amount of ties.
 */
void score(){
  printf("Player: %d\t Computer: %d\t Ties: %d\n", player, computer, tie);
}

/**
 *Randomly generated computer selection from 0-2.
 *0: Rock, 1: Paper, 2:Scisscors
 */
char getComputerChoice(){
  srand(time(NULL)); //initialize RNG
  int i = rand() % 3; 
  //Switch case to apply RNG
  switch(i){
  case 0:
    return 'r'; //Computer chooses rock
  case 1:
    return 'p'; //Computer chooses paper
  case 2: 
    return 's'; //Computer chooses scisscor
  }
}

/**
 *Results
 *Compares the playerChoice with computerChoice to determine who won the 
 *round. "Incorrect Input" if the user enters char besides r, p, or s. 
 */
void results(){
  //For correct inputs (r, p, s).
  if(playerChoice == 'r' || playerChoice == 'p' || playerChoice == 's'){ 
    if(playerChoice == 'r' && computerChoice == 'r'){ 
      printf("two rocks, so it's a tie!");
      tie++;
    }
    else if(playerChoice == 'r' && computerChoice == 's'){
      printf("rock vs scissors, so PLAYER wins!");
      player++;
    }
    else if(playerChoice == 'r' && computerChoice == 'p'){
      printf("rock vs paper, so COMPUTER wins!");
      computer++;
    }
    else if(playerChoice == 'p' && computerChoice == 'p'){
      printf("two papers, so it's a tie!");
      tie++;
    }
    else if(playerChoice == 'p' && computerChoice == 'r'){
      printf("paper vs rock, so PLAYER wins!");
      player++;
    }
    else if(playerChoice == 'p' && computerChoice == 's'){
      printf("paper vs scissors, so COMPUTER wins!");
      computer++;
    }
    else if(playerChoice == 's' && computerChoice == 's'){
      printf("two scissors, so it's a tie!");
      tie++;
    }
    else if(playerChoice == 's' && computerChoice == 'p'){
      printf("scissors vs paper, so PLAYER wins!");
      player++;
    }
    else if(playerChoice == 's' && computerChoice == 'r'){
      printf("scissors vs rock, so COMPUTER wins");
      computer++;
    }
  }
  else if(playerChoice == 'q' || playerChoice =='Q'){ 
    flag = 1; //change flag from 0 to end loop and quit game.
  } else{
    printf("Incorrect Input"); //For incorrect inputs.
  }
}
