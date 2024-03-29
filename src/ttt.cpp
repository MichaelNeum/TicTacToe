#include <iostream>
#include <algorithm>
#include <array>
#include <tuple>
#include "userinput.hpp"
#include "minimax.hpp"

std::array<std::array<int, 3>, 3> field = {{{0,0,0}, {0,0,0}, {0,0,0}}};

constexpr int Human = 1;

void printField();
std::string symbol(int input);
bool checkWin(std::tuple<int, int>);
int row(std::tuple<int,int> lastTick);
int column(std::tuple<int,int> lastTick);
std::string Player(int,bool);
bool choice();
bool playAgain();

/*************
TikTakToe Game 
*************/
int main()
{
    std::cout << "Welcome to TicTacToe!\nUse:\nq w e\na s d \ny x c\nto place your marks!\n\nDo you want to play vs another human{1} or vs the computer{2}?: " << std::endl;
    bool pvp = choice();
    int player = Human;
    int count = 0;
    UserInput userInput(&field, &count);
    Minimax miniMax;
    std::tuple<int, int> lastPlay = {-1,-1};
    std::cout << "TicTacToe" << std::endl;
    while(1) {
        player = count % 2 + 1;
        count++;
        if(player == Human || pvp) {
            std::string input;
            std::cin >> input;
            if(input == "exit") break;
            lastPlay = userInput.handleUserInput(input, player);
        }
        else {
            std::array<int,3> play = miniMax.minimax(field, miniMax.depth(field), Computer, lastPlay);
            lastPlay = {play[0], play[1]};
            field[play[0]][play[1]] = player;
        }
        bool result = checkWin(lastPlay);
        printField();
        if(result) {
            std::cout << Player(player, pvp) << " won!" << std::endl;
            if(!playAgain()) break;
        }
        if(miniMax.depth(field) == 0) {
            std::cout << "Nobody won!" << std::endl;
            if(!playAgain()) break;
        }
    }
    return 0;
}

void printField() {
    for(int i = 0; i < 3; i++) {
        std::cout << symbol(field[i][0]) << "|" << symbol(field[i][1]) << "|" << symbol(field[i][2]) << std::endl;
        if(i != 2) std::cout << "-----" << std::endl;
    }
    std::cout << "\n";
}

std::string symbol(int input) {
    if(input == 1) return "o";
    else if(input == 2) return "x";
    return " ";
}

bool checkWin(std::tuple<int, int> lastTick) {
    if(row(lastTick) == -1) return false;
    bool result = false;
    for(int i = 0; i < 2; i++) {
        if(field[row(lastTick)][i] != field[row(lastTick)][i+1]) {
            result = false;
            break;
        }
        result = true;
    }
    if(result) return result;
    for(int i = 0; i < 2; i++) {
        if(field[i][column(lastTick)] != field[i+1][column(lastTick)]) {
            result = false;
            break;
        }
        result = true;
    }
    if(result) return result;
    for(int i = 0; i < 2; i++) {
        if(field[i][i] != field[i+1][i+1] || field[1][1] == 0) {
            result = false;
            break;
        }
        result = true;
    }
    if(result) return result;
    for(int i = 0; i < 2; i++) {
        if(field[i][2-i] != field[i+1][2-i-1] || field[1][1] == 0) {
            result = false;
            break;
        }
        result = true;
    }
    return result;
}

int row(std::tuple<int,int> lastTick) {
    return std::get<0>(lastTick);
}

int column(std::tuple<int,int> lastTick) {
    return std::get<1>(lastTick);
}

std::string Player(int player, bool pvp) {
    if(player == 1 && pvp) return "Player 1";
    else if(player == 2 && pvp) return "Player 2";
    else if(player == 1) return "Human";
    else return "Computer";
}

bool choice() {
    std::string result;
    std::cin >> result;
    return result == "1";
}

bool playAgain() {
    std::cout << "Do you want to play again? yes{1} no{2}: " << std::endl;
    std::string result;
    std::cin >> result;
    field = {{{0,0,0}, {0,0,0}, {0,0,0}}};
    return result == "1";
}