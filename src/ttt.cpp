#include <iostream>
#include <algorithm>
#include <array>
#include "userinput.hpp"

std::array<std::array<int, 3>, 3> field = {{{0,0,0}, {0,0,0}, {0,0,0}}};

void printField(std::array<std::array<int, 3>, 3> field);
std::string symbol(int input);

/*************
TikTakToe Game 
*************/
int main()
{
    UserInput ui(&field);
    while(1) {
        std::string userInput;
        std::cin >> userInput;
        if(userInput == "exit") break;
        ui.handleUserInput(userInput);
        printField(field);
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