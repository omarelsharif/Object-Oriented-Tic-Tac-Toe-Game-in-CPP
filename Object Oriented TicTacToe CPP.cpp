// Omar El-Sharif (3/22/2023)

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to print the tic-tac-toe board
void printBoard(const vector<vector<char>>& board) {
    cout << "  1 2 3\n";
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }
    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return true;
        }
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    // No winner found
    return false;
}

// Function to check if the board is full (i.e., a draw)
bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    // Initialize the board
    vector<vector<char>> board(3, vector<char>(3, ' '));

    // Get player names
    string player1, player2;
    cout << "Enter Player 1's name: ";
    cin >> player1;
    cout << "Enter Player 2's name: ";
    cin >> player2;

    // Print the initial board
    printBoard(board);

   // Main game loop
char currentPlayer = 'X';
int row, col;
while (true) {
    // Get the player's move
    cout << " " << endl; 
    cout << currentPlayer << "'s turn. Enter row (1-3) and column (1-3) separated by a space: ";
    cin >> row >> col;
    row--; // Convert to 0-based indexing
    col--; // Convert to 0-based indexing

    // Check if the move is valid
    if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
        cout << "Invalid move. Try again.\n";
        continue;
    }

    // Make the move
    board[row][col] = currentPlayer;

    // Print the updated board
    printBoard(board);

    // Check if the game is over
    if (checkWin(board, currentPlayer)) {
        cout << currentPlayer << " wins!\n";
        break;
    }
    if (checkDraw(board)) {
        cout << "Draw!\n";
        break;
    }

    // Switch to the other player
    if (currentPlayer == 'X') {
        currentPlayer = 'O';
    } else {
        currentPlayer = 'X';
    }
}

// End of game
cout << "Thanks for playing!\n";
return 0;
}