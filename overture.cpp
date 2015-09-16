#include <iostream>

std::string board = "";
std::string empty = ".";
std::string signs = "XO";

void drawBoard() {
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0) std::cout << std::endl;
        std::cout << board[i];
    }
    std::cout << std::endl << std::endl;
}

bool correctMove(short move) {
    if (move >= 1 && move <= 9) {
        if (board.substr(move-1,1) == empty) {
            return true;
        }
    }
    return false;
}

short findVictory() {
    for (int i = 0; i < 3; i++) {
        if (board.substr(i*3,1) != empty && board.substr(i*3,1) == board.substr(i*3+1,1) && board.substr(i*3,1) == board.substr(i*3+2,1)) {
            return signs.find(board.substr(i*3,1));
        }
        if (board.substr(i,1) != empty && board.substr(i,1) == board.substr(i+3,1) && board.substr(i,1) == board.substr(i+6,1)) {
            return signs.find(board.substr(i,1));
        }
    }
    if (board.substr(4,1) != empty) {
        if (board.substr(4,1) == board.substr(2,1) && board.substr(4,1) == board.substr(6,1)) {
            return signs.find(board.substr(4,1));
        }
        if (board.substr(4,1) == board.substr(0,1) && board.substr(4,1) == board.substr(8,1)) {
            return signs.find(board.substr(4,1));
        }
    }
    return -1;
}

int main() {
    short turn = 0;
    short move, v;
    for (int i = 0; i < 9; i++) board += empty;
    drawBoard();
    while (turn < 9) {
        move = -1;
        while (move == -1) {
            std::cout << "TURA " << signs.substr(turn % 2, 1) << std::endl;
            std::cout << "Podaj ruch: [1-9] ";
            std::cin >> move;
            if (!correctMove(move)) {
                std::cout << "Ruch niepoprawny" << std::endl;
                move = -1;
            }
        }
        board.replace(move-1, 1, signs.substr(turn % 2, 1));
        turn++;
        drawBoard();
        v = findVictory();
        if (v != -1) {
            std:: cout << "WYGRYWA " << signs.substr(v, 1) << std::endl;
            return 0;
        }
    }
    drawBoard();
    std::cout << "REMIS" << std::endl;
    return 0;
}