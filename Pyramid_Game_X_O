#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "../include/BoardGame_Classes.hpp"
using namespace std;

// Set the board
Pyramid_Game::Pyramid_Game () {
    n_rows =3 ; n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = '_';
    }
}

bool Pyramid_Game::update_board (int x, int y, char mark){

    if (!(x < 0 || x > 3 || y < 0 || y > 5 || ( x == 0 && (y == 0 || y == 1 || y == 3 || y == 4))||(x == 1 && (y == 0 || y == 4)))
    && (board[x][y] == '_')) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}


void Pyramid_Game::display_board() {
    for (int i: {0}) {
        cout << "\n                   ";
        for (int j: {2}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2)<<" |" << board [i][j] << "|";
        }
        cout << '\n';
    }
    for (int i: {1}) {
        cout << "\n          ";
        for (int j: {1,2,3}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2)<<" |" << board [i][j] << "|";
        }
        cout << '\n';
    }
    for (int i: {2}) {
        cout << "\n ";
        for (int j: {0,1,2,3,4}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2)<<" |" << board [i][j] << "|";
        }
        cout << '\n';
    }
    cout << endl;
}


bool Pyramid_Game::is_winner() {
    for (int i=0; i <=2; i++ ){
        for (int j = 0; j<=4;j++){

            if (board [2][j] == board [2][j+1] && board [2][j] == board [2][j+2] && board [2][j] != '_') {
                return true;
            }
        }
    }
    if ((board [0][2] == board [1][3] && board [0][2] == board [2][4] &&  board [0][2] != '_') || ( board [0][2] == board [1][1] && board [0][2] == board [2][0] && board [0][2] != '_' )){
        return true;
    }
    if (board [1][1] == board [1][3] && board [1][1] == board [1][2] && board [1][1] != '_') {
        return true;
    }
    if (board [0][2] == board [1][2] && board [0][2] == board [2][2] && board [0][2] != '_') {
        return true;
    }
    return false;
}


bool Pyramid_Game::is_draw() {
    return (n_moves == 9 && !is_winner());
}

bool Pyramid_Game::game_is_over () {
    return n_moves >= 9;
}
