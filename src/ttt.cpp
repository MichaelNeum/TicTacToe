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
bool checkField(int x, int y);

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
    if(input.length() > 1) {
        std::cout << "Invalid input. Try agian!" << std::endl;
        return;
    }
    switch(hashit(input)){
        case eQ:
            if(checkField(0,0)) return;
            ticks[0][0] = 1;
            break;
        case eW:
            if(checkField(0,1)) return;
            ticks[0][1] = 1;
            break;
        case eE:
            if(checkField(0,2)) return;
            ticks[0][2] = 1;
            break;
        case eA:
            if(checkField(1,0)) return;
            ticks[1][0] = 1;
            break;
        case eS:
            if(checkField(1,1)) return;
            ticks[1][1] = 1;
            break;
        case eD:
            if(checkField(1,2)) return;
            ticks[1][2] = 1;
            break;
        case eY:
            if(checkField(2,0)) return;
            ticks[2][0] = 1;
            break;
        case eX:
            if(checkField(2,1)) return;
            ticks[2][1] = 1;
            break;
        case eC:
            if(checkField(2,2)) return;
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

bool checkField(int x, int y) {
    if(ticks[x][y] != 0) {
        std::cout << "Field already placed. Try another one!" << std::endl;
        return true;
    }
    return false;
}