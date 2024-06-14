
//TIC-TAC-TOE Game
#include <iostream>
using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE];

void initializeBoard() {
    for(int i = 0; i < SIZE; ++i) {
        for(int j = 0; j < SIZE; ++j) {
            board[i][j] = '-';
        }
    }
}

void displayBoard() {
    for(int i = 0; i < SIZE; ++i) {
        for(int j = 0; j < SIZE; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkWin(char player) {
    // Check rows, columns, and diagonals for win condition
    for(int i = 0; i < SIZE; ++i) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

bool checkDraw() {
    for(int i = 0; i < SIZE; ++i) {
        for(int j = 0; j < SIZE; ++j) {
            if(board[i][j] == '-') return false;
        }
    }
    return true;
}

void makeMove(int row, int col, char player) {
    if(row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == '-') {
        board[row][col] = player;
    }
}

int main() {
    char currentPlayer = 'X';
    initializeBoard();

    while(true) {
        displayBoard();
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row column): ";
        cin >> row >> col;

        makeMove(row, col, currentPlayer);
        if(checkWin(currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        } else if(checkDraw()) {
            cout << "It's a draw!" << endl;
            break;
        }

        currentPlayer = (currentPlayer == 'X')? 'O' : 'X'; // Switch player
    }

    cout << "Do you want to play again? (y/n): ";
    char playAgain;
    cin >> playAgain;
    if(playAgain == 'y' || playAgain == 'Y') {
        main(); // Restart the game
    }

    return 0;
}
