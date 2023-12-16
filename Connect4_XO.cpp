#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "../include/BoardGame_Classes.hpp"
using namespace std;

Connect4_XO_board::Connect4_XO_board(){
    //board 6*7 bs fe row zyada(7) invisible el values kolha feha b wahed explained in line 19
    n_rows = 6, n_cols = 7;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++){
            board[i][j] = 0;
            arr[i][j]=0;
        }
    }
    // invisible contanier taht khales el values kolha bta3to b wahed 1 3shan kol ama anzl x aw o tnzl 3leh mydesh error
    // mynf3sh anzl x aw o gher lma ykon tahta 1 aka lw fe value tahty 0 msh hynf3 anzl 3leh
    // fa lma agy anzl awl mra hydey error so 3mlt invisible container el values bta3to b 1
    for (int i = 0; i < 7; ++i) {
        arr[6][i]=1;
    }
}

bool Connect4_XO_board::update_board (int x, int y, char mark) {
    // Only update if move is valid
    if (y < 0 || y > 6) return false; // Check if column is out of bounds
    bool valid = false; // Initialize a boolean variable to store the validity of the move
    for (int i = n_rows - 1; i >= 0; i--) { // Loop from bottom row to top row
        if (board[i][y] == 0) { // Check if cell is empty
            x = i; // Update x with the correct row number
            valid = true; // Set valid to true
            break; // Break out of the loop
        }
    }
    if (valid) { // If the move was valid
        board[x][y] = toupper(mark); // Update board with mark
        arr[x][y] = 1; // Update arr with 1
        n_moves++; // Increment number of moves
    }
    return valid; // Return the validity of the move
}


void Connect4_XO_board::display_board(){
    // i= 3awamed beltol
    for (int i: {0,1,2,3,4,5}) {
        cout << "\n| ";
        // j= sofof bel3rd
        for (int j: {0,1,2,3,4,5,6}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board[i][j] << " |";
        }
        cout << "\n----------------------------------------------------------";
    }
    cout << endl;
}

bool Connect4_XO_board::is_winner() {
    for (int i = 0; i < 6; ++i) {  // Check all rows
        for (int j = 0; j < 4; ++j) {
            // row check , el element eli ana feha eli rakmha i w j lazm tkon = ll next corresponding 3 elements to the right
            if ((board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] == board[i][j + 3] &&
                 (board[i][j] == 'O' || board[i][j] == 'X')))
                return true;


        }
    }
            // column check ,el element eli ana feha eli rakmha i w j lazm tkon = ll next corresponding 3 elements down
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 7; ++j) {
            if ((board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j] &&
                 board[i][j] == board[i + 3][j] && (board[i][j] == 'O' || board[i][j] == 'X')))
                return true;
        }

    }

    for (int i = 0; i <= 2; ++i) {
        for (int j = 0; j <= 3; ++j) {
            // diagonal check from top left to bottom right
            if ((board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2] &&
                 board[i][j] == board[i + 3][j + 3] && (board[i][j] == 'O' || board[i][j] == 'X')))
                return true;
        }

    }
    // diagonal check from top right to bottom left
    for (int i = 0; i <= 2; ++i) {
        for (int j = 6; j >= 3; --j) {
            if ((board[i][j] == board[i + 1][j - 1] && board[i][j] == board[i + 2][j - 2] &&
                 board[i][j] == board[i + 3][j - 3] && (board[i][j] == 'O' || board[i][j] == 'X')))
                return true;
        }
    }

   return false;
}

bool Connect4_XO_board::is_draw(){
    return (n_moves == 42 && !is_winner());
}
bool Connect4_XO_board::game_is_over(){
    return n_moves >= 42;
}
