#include <iostream>
#include <algorithm>
#include <array>

std::array<std::array<int, 3>, 3> ticks = {0};

void printField(std::array<std::array<int, 3>, 3> ticks);
std::string symbol(int input);
void handleUserInput(std::string input);

int main()
{
    handleUserInput("Hello");
    printField(ticks);
    return 0;
}

void handleUserInput(std::string input) {
    if(input.length() > 1) std::cout << "Invalid input. Try agian!" << std::endl;
}

void printField(std::array<std::array<int, 3>, 3> ticks) {
    for(int i = 0; i < 5; i++) {
        if(i % 2 == 0) {
            std::cout << symbol(ticks[i][0]) << "|" << symbol(ticks[i][1]) << "|" << symbol(ticks[i][2]);
        }
        else {
            std::cout << "-----";
        }
        std::cout << "\n";
    }
}

std::string symbol(int input) {
    if(input == 1) return "o";
    else if(input == 2) return "x";
    return " ";
}