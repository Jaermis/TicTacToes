//the C version of the Tic Tac Toe Game

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

char board[9] = {'-', '-', '-',
                 '-', '-', '-',
                 '-', '-', '-'};
char currentPlayer = 'X';
char winner = '\0';
bool gameRunning = true;

void printBoard() {
    printf("| %c | %c | %c |\n", board[0], board[1], board[2]);
    printf("+---+---+---+\n");
    printf("| %c | %c | %c |\n", board[3], board[4], board[5]);
    printf("+---+---+---+\n");
    printf("| %c | %c | %c |\n", board[6], board[7], board[8]);
}

void playerInput() {
    int inp;
    printf("Enter a number from 1-9: ");
    scanf("%d", &inp);
    inp--;
    if (inp >= 0 && inp <= 8 && board[inp] == '-') {
        board[inp] = currentPlayer;
    } else {
        printf("Invalid input. Sorry!\n");
    }
}

bool checkHorizontal() {
    if (board[0] == board[1] && board[1] == board[2] && board[0] != '-') {
        winner = board[0];
        return true;
    } else if (board[3] == board[4] && board[4] == board[5] && board[3] != '-') {
        winner = board[3];
        return true;
    } else if (board[6] == board[7] && board[7] == board[8] && board[6] != '-') {
        winner = board[6];
        return true;
    }
    return false;
}

bool checkRow() {
    if (board[0] == board[3] && board[3] == board[6] && board[0] != '-') {
        winner = board[0];
        return true;
    } else if (board[1] == board[4] && board[4] == board[7] && board[1] != '-') {
        winner = board[1];
        return true;
    } else if (board[2] == board[5] && board[5] == board[8] && board[2] != '-') {
        winner = board[2];
        return true;
    }
    return false;
}

bool checkDiag() {
    if (board[0] == board[4] && board[4] == board[8] && board[0] != '-') {
        winner = board[0];
        return true;
    } else if (board[2] == board[4] && board[4] == board[6] && board[2] != '-') {
        winner = board[2];
        return true;
    }
    return false;
}

bool checkTie() {
    for (int i = 0; i < 9; i++) {
        if (board[i] == '-') {
            return false;
        }
    }
    printBoard();
    printf("It's a tie!\n");
    return true;
}

bool checkWin() {
    return checkDiag() || checkHorizontal() || checkRow();
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? '0' : 'X';
}

void comp() {
    while (currentPlayer == '0') {
        int position = rand() % 9;
        if (board[position] == '-') {
            board[position] = '0';
            switchPlayer();
        }
    }
}

int main() {
    srand(time(NULL));
    while (gameRunning) {
        printBoard();
        playerInput();
        switchPlayer();
        comp();
        if (checkWin() || checkTie()) {
            gameRunning = false;
        }
    }
    if (winner != '\0') {
        printBoard();
        printf("The winner is %c!\n", winner);
    }
    return 0;
}
