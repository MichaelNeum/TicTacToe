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

/*************
TikTakToe Game 
*************/
int main()
{
    while(1) {
        std::string input;
        std::cin >> input;
        if(input == "exit") break;
        handleUserInput(input);
    }
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
            ticks[0][0] = 1;
            break;
        case eW:
            ticks[0][1] = 1;
            break;
        case eE:
            ticks[0][2] = 1;
            break;
        case eA:
            ticks[1][0] = 1;
            break;
        case eS:
            ticks[1][1] = 1;
            break;
        case eD:
            ticks[1][2] = 1;
            break;
        case eY:
            ticks[2][0] = 1;
            break;
        case eX:
            ticks[2][1] = 1;
            break;
        case eC:
            ticks[2][2] = 1;
            break;
        default:
            break;
    }
    printField(ticks);
}

void printField(std::array<std::array<int, 3>, 3> ticks) {
    for(int i = 0; i < 3; i++) {
        std::cout << symbol(ticks[i][0]) << "|" << symbol(ticks[i][1]) << "|" << symbol(ticks[i][2]) << std::endl;
        if(i != 2) std::cout << "-----" << std::endl;
    }
    std::cout << "\n";
}

std::string symbol(int input) {
    if(input == 1) return "o";
    else if(input == 2) return "x";
    return " ";
}