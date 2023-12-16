#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "../include/BoardGame_Classes.hpp"
using namespace std;

// Set the board
five_XO::five_XO(){
    n_rows = n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool five_XO::update_board (int x, int y, char mark){
    // Only update if move is valid
    if (!(x<0 || x>4 || y<0 || y>4) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}

// Display the board and the pieces on it
void five_XO::display_board() {
    for (int i: {0,1,2,3,4}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4}) {
            if(true){
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
            }
        }
        cout << "\n-----------------------------------------------------------";
    }
    cout << endl;
}

bool is_winner(){
    return false;
}
// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
bool five_XO::is_winner(int& m) {
    if (n_moves == 24) {
        for (int i = 0; i <= 4; ++i) {
            for (int j = 0; j <= 2; ++j) {// row win
                if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2]) {
                    if (board[i][j] == 'X') {
                        player1_wins++;
                    } else {
                        player2_wins++;
                    }
                }
            }
        }

        for (int i = 0; i <= 2; ++i) {// column win
            for (int j = 0; j <= 4; ++j) {
                if (board[i][j] == board[i + 1][j] && board[i + 1][j] == board[i + 2][j]) {
                    if (board[i][j] == 'X') {
                        player1_wins++;
                    } else {
                        player2_wins++;
                    }
                }
            }
        }

        for (int i = 0; i <= 2; ++i) {// diag
            for (int j = 0; j <= 2; ++j) {
                if (board[i][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 2][j + 2]) {
                    if (board[i][j] == 'X') {
                        player1_wins++;
                    } else {
                        player2_wins++;
                    }
                }
            }
        }

        for (int i = 0; i <= 2; ++i) {// diag2
            for (int j = 2; j <= 4; ++j) {
                if (board[i][j] == board[i + 1][j - 1] && board[i + 1][j - 1] == board[i + 2][j - 2]) {
                    if (board[i][j] == 'X') {
                        player1_wins++;
                    } else {
                        player2_wins++;
                    }
                }
            }
        }
    }

    if (n_moves == 24) {
        if (player1_wins > player2_wins) {
            m = 1;
            return true;
        } else if (player2_wins > player1_wins) {
            m = 0;
            return true;
        } else {
            m = -1; // Indicates a tie
            return true;
        }
    }
    return false;
}




// Return true if 9 moves are done and no winner
bool five_XO::is_draw() {
    return (n_moves == 24 && !is_winner(player1_wins));
}


bool five_XO::game_is_over () {
    return n_moves >= 24;
}

bool five_XO::is_winner() {
    return false;
}
