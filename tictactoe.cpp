//
//  main.cpp
//  TicTacTo
//
//  Created by Tarek Abdelrahman on 2019-06-07.
//  Modified by Tarek Abdelrahman on 2020-09-17.
//  Copyright © 2019-2020 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.
//
//  ECE244 Student: Complete the skeletal code of the main function in this file

#include <iostream>
#include <string>
using namespace std;

#include "globals.h"
#include "GameState.h"

// Function prototype for playMove
void playMove(GameState&);

// The main function
int main() {

  /**********************************************************************************/
  /* Create an initialized game state object                                        */
  /**********************************************************************************/
  GameState game_state;

  // Read two integers from the user that represent the row and column
  // the player would like to place an X or an O in
  // You can assume there will be no formatting errors in the input

  int row;
  int col;

  while (!game_state.get_gameOver()) {
    std::cout << "Enter row and column of a grid cell: ";
    std::cin >> row >> col;

    // Check that the read row and column values are valid grid coordinates, and then inform the user.
    if ( (row < 0) || (row > 2) || (col < 0) || (col > 2) ) {
      std::cout << "Invalid board coordinates " << row << " " << col << endl << endl;
      continue;
    }
    // The coordinates are valid; set the selectedRow and selectedColumn
    // members of the game state to the read values
    game_state.set_selectedRow(row);
    game_state.set_selectedColumn(col);

    // Call playMove
    playMove(game_state);
      
    // Print the GameState object, as prescribed in the handout
    std::cout << "Selected row " << game_state.get_selectedRow() <<" and column " << game_state.get_selectedColumn() << endl;
    std::cout << "Game state after playMove:" << endl;
    std::cout << "Board:" << endl;

    // Print board
    int tmp = 0;
    for (int i = 0; i < 3; i++){
    std::cout << "   ";
      for (int j = 0; j < 3; j++){
        tmp = game_state.get_gameBoard(i, j);
        if (tmp == Empty) std::cout << "B ";
        if (tmp == X) std::cout << "X ";
        if (tmp == O) std::cout << "O ";
      }
    std::cout << endl;
    }

    std::cout << "moveValid: " << std::boolalpha << game_state.get_moveValid() << endl; 
    std::cout << "gameOver: " << std::boolalpha << game_state.get_gameOver() << endl; 
    std::cout << "winCode: " << game_state.get_winCode() << endl; 
    std::cout << endl;
  }
return 0;
}
