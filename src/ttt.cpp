#include <iostream>
#include <algorithm>
#include <array>

enum stringCode {
    eQ, eW, eE,
    eA, eS, eD,
    eY, eX, eC,
    eError
};

std::array<std::array<int, 3>, 3> ticks = {{{0,0,0}, {0,0,0}, {0,0,0}}};

void printField(std::array<std::array<int, 3>, 3> ticks);
std::string symbol(int input);
void handleUserInput(std::string input);

int main()
{
    std::string input;
    std::cin >> input;
    handleUserInput(input);
    printField(ticks);
    return 0;
}

stringCode hashit(std::string const& input) {
    if(input == "q") return eQ;
    else if(input == "w") return eW;
    else if(input == "e") return eE;
    else if(input == "a") return eA;
    else if(input == "s") return eS;
    else if(input == "d") return eD;
    else if(input == "y") return eY;
    else if(input == "x") return eX;
    else if(input == "c") return eC;
    else return eError;
}

void handleUserInput(std::string input) {
    if(input.length() > 1) std::cout << "Invalid input. Try agian!" << std::endl;
    switch(hashit(input)){
        case eQ:
            std::cout << "done";
            break;
        default:
            break;
    }
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