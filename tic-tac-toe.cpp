#include <iostream>
using namespace std;

// Array for the board
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

// Variable Declarations
int choice;
int row, column;
char turn = 'X';
bool draw = false;

// Function to show the current status of the gaming board
void display_board() {
    system("clear");  // Clear the screen (for Unix-like systems)
    // You can use "cls" for Windows systems
    cout << "TIC TAC TOE GAME\n";
    cout << "Player 1 [X] - Player 2 [O]\n\n";
    cout << "     |     |     \n";
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  \n";
    cout << "     |     |     \n";
}

// Function to get the player input and update the board
void player_turn() {
    int row, column;

    if (turn == 'X') {
        cout << "Player 1 [X] turn: ";
    } else if (turn == 'O') {
        cout << "Player 2 [O] turn: ";
    }

    cin >> choice;

    // Convert choice to row and column
    switch (choice) {
        case 1: row = 0; column = 0; break;
        case 2: row = 0; column = 1; break;
        case 3: row = 0; column = 2; break;
        case 4: row = 1; column = 0; break;
        case 5: row = 1; column = 1; break;
        case 6: row = 1; column = 2; break;
        case 7: row = 2; column = 0; break;
        case 8: row = 2; column = 1; break;
        case 9: row = 2; column = 2; break;
        default:
            cout << "Invalid Move\n";
            return;
    }

    if (board[row][column] != 'X' && board[row][column] != 'O') {
        board[row][column] = turn;
        if (turn == 'X') {
            turn = 'O';
        } else {
            turn = 'X';
        }
    } else {
        cout << "Box already filled! Please choose another.\n";
    }
}

// Function to check if the game is over (win, draw, or ongoing)
bool gameover() {
    for (int i = 0; i < 3; i++) {
        // Check rows and columns for a win
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] ||
            board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return false;
        }
    }

    // Check diagonals for a win
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] ||
        board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return false;
    }

    // Check for a draw
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return true; // The game is still ongoing
            }
        }
    }

    draw = true;
    return false; // It's a draw
}

int main() {
    cout << "TIC TAC TOE GAME\n";
    cout << "Player 1 [X] - Player 2 [O]\n";

    while (gameover()) {
        display_board();
        player_turn();
    }

    if (turn == 'X' && !draw) {
        cout << "Player 1 [X] wins!\n";
    } else if (turn == 'O' && !draw) {
        cout << "Player 2 [O] wins!\n";
    } else {
        cout << "It's a draw!\n";
    }

    return 0;
}
