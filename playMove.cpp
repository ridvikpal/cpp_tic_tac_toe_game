//
//  playMove.cpp
//  TicTacToe
//
//  Created by Tarek Abdelrahman on 2019-06-07.
//  Modified by Tarek Abdelrahman on 2020-09-17.
//  Copyright © 2019-2020 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.
//
//  ECE244 Student: write your code for playMove in this file

#include "globals.h"
#include "GameState.h"

// Preceding this point the given row and column are within range of the board size

void playMove(GameState& game_state) {
  int player=0, counter=0, i=0, j=0;
  
  // Set the player
  if (game_state.get_turn() == true){
    player = X;
  }else{
    player = O;
  }
  
  // Check if the given row and column are empty
  if (game_state.get_gameBoard(game_state.get_selectedRow(), game_state.get_selectedColumn()) == Empty){
    
    game_state.set_moveValid(true);
    // Update the board with the correct player token
    game_state.set_gameBoard(game_state.get_selectedRow(), game_state.get_selectedColumn(), player);

  }else{
    game_state.set_moveValid(false);
  }
  
  // Check for winCode 8 and set accordingly
  if(game_state.get_gameBoard(2, 0) == player && game_state.get_gameBoard(1, 1) == player && game_state.get_gameBoard(0, 2) == player){
    game_state.set_winCode(8);
    game_state.set_gameOver(true);
    return;
  }
  
  // Check for winCodes 7 and set accordingly
  if(game_state.get_gameBoard(0, 0) == player && game_state.get_gameBoard(1, 1) == player && game_state.get_gameBoard(2, 2) == player){
    game_state.set_winCode(7);
    game_state.set_gameOver(true);
    return;
  }
  
  // Check for winCodes 4 to 6 and set accordingly
  for (i = 0; i < 3; i++){
    if(game_state.get_gameBoard(0, i) == player && game_state.get_gameBoard(1, i) == player && game_state.get_gameBoard(2, i) == player){
      game_state.set_winCode(i+4);
      game_state.set_gameOver(true);
      return;
    }
  }
  
  // Check for winCodes 1 to 3 and set accordingly  
  for (i = 0; i < 3; i++){
    if(game_state.get_gameBoard(i, 0) == player && game_state.get_gameBoard(i, 1) == player && game_state.get_gameBoard(i, 2) == player){
      game_state.set_winCode(i+1);
      game_state.set_gameOver(true);
      return;
    }
  }
  
  // Check for winCode 0 which is a draw
  for (i = 0; i < 3; i++){
    for (j = 0; j < 3; j++){
      if (game_state.get_gameBoard(i, j) != Empty){
        counter++;
      }
    }
  }
  if (counter == 9){
    game_state.set_winCode(0);
    game_state.set_gameOver(true);
    return;
  }

  // Swap turns accordingly
  if (game_state.get_moveValid() == true){
    if (player == X){
      game_state.set_turn(false);
    }else{
      game_state.set_turn(true);
    }
  }
}

