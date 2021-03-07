#include <iostream>
#include <algorithm>
#include <array>
#include <tuple>
#include "userinput.hpp"
#include "minimax.hpp"

std::array<std::array<int, 3>, 3> field = {{{0,0,0}, {0,0,0}, {0,0,0}}};

void printField(std::array<std::array<int, 3>, 3> field);
std::string symbol(int input);
bool checkWin(std::tuple<int, int>);
int row(std::tuple<int,int> lastTick);
int column(std::tuple<int,int> lastTick);

/*************
TikTakToe Game 
*************/
int main()
{
    int player = 1;
    int count = 0;
    UserInput ui(&field, &count);
    Minimax mm;
    while(1) {
        player = count % 2 + 1;
        count++;
        std::string userInput;
        std::cin >> userInput;
        if(userInput == "exit") break;
        bool result = checkWin(ui.handleUserInput(userInput, player));
        printField(field);
        if(result) {
            std::cout << "Player " << player << " won!";
            break;
        }
        std::cout << mm.depth(field) << std::endl;
    }
    return 0;
}

void printField(std::array<std::array<int, 3>, 3> field) {
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